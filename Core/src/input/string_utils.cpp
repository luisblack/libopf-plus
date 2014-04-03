#include <utils/string_utils.h>

using namespace std;

namespace opf
{
std::vector<std::string> &split(const string &s, const string delimiters, vector<string> &elems) {
    std::string item;

    int pos = 0;
    for(;;)
    {
        int newpos = s.find_first_of(delimiters, pos+1);
        if(newpos == -1)
        {
            elems.push_back(s.substr(pos));
            break;
        }
        elems.push_back(s.substr(pos, newpos-pos));
        pos = newpos + 1;
    }
    return elems;
}


std::vector<std::string> split(const string &s, const string delimiters) {
    vector<string> elems;
    split(s, delimiters, elems);
    return elems;
}

}

