#include <input/csv_format.h>
#include <map>
#include <list>
#include <exception/invalid_format_exception.h>

using namespace std;

namespace opf
{

    const string DELIMITERS = ";,";
    const char NEW_LINE = '\n';

    const string DOUBLE_TYPE = "double";

    namespace output
    {
        void csv(ostream& o, Patterns& p)
        {
            throw opf::LazyProgramerException("CSV is read only");
        }
    }

    namespace input
    {

        bool check_types(const string& line)
        {
            vector<string> types = split(line, DELIMITERS);

            //check if all features are from double type (no strings allowed)
            //they can be integer???
            for (int i = 0; i < types.size() - 1; ++i) {
                if(types[i] != DOUBLE_TYPE)
                {
                    return true;
                }
            }
            return false;
        }

        bool readLine(const string& line, vector<double>& feats, string &label)
        {
            vector<string> values = split(line, DELIMITERS);
            int feats_number = values.size()-1;

            feats.resize(feats_number);

            for (int i = 0; i<feats_number; ++i) {
                try
                {
                    feats[i] = stod(values[i]);
                }
                catch(invalid_argument e)
                {
                    return true;
                }
            }

            label = values.back();

            return false;
        }

        void csv(istream& input, Patterns& p)
        {
            string line;

            map<string, int> label_map;
            list< vector<double> > feats_list;
            list< string > label_list;

            input.ignore(numeric_limits<int>::max(), NEW_LINE);//ignore the classes name line
            getline(input, line);//types line

            if(check_types(line))
                throw InvalidFormatException("The features should be double.");

            //read values
            int cur_line = 2;//the samples starts on line 2
            while(input.peek()!=EOF)
            {
                getline(input, line);

                vector<double> feats;
                string label;
                if(readLine(line, feats, label))
                    throw InvalidFormatException("There is a non double feature on line " + line);

                feats_list.push_back(feats);
                label_list.push_back(label);

                if(label_map.find(label)==label_map.end())//new label
                    label_map[label] = label_map.size() + 1;

                ++cur_line;
            }


            //write in pattern
            p.set_number_of_classes(label_map.size());
            p.set_number_of_patterns(label_list.size());

            int idx=0;
            for(auto label : label_list){
                Pattern &pattern = p[idx];
                pattern.set_class_value(label_map[label]);
                pattern.set_index(idx);
                ++idx;
            }

            idx=0;
            for(auto feats : feats_list){
                Pattern &pattern = p[idx++];
                pattern.set_dimension(feats.size());
                for (int j = 0; j < feats.size(); ++j) {
                    pattern[j] = feats[j];
                }
            }
        }
    }
}
