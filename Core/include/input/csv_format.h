#ifndef CVS_FORMAT_H
#define CVS_FORMAT_H

#include <iostream>
#include <input/patterns.h>
#include <input/pattern.h>
#include <exception/lazy_programer_exception.h>

#include <utils/string_utils.h>

#include <limits>

namespace opf {

const char COMMA = ',';
const char NEW_LINE = '\n';

namespace output {

    void csv(ostream& o, Patterns& p)
    {
        throw opf::LazyProgramerException("CSV is read only");
    }

}

namespace input {

    void csv(istream& i, Patterns& p)
    {
        string line;

        i.ignore(numeric_limits<int>::max(), NEW_LINE);//ignore the classes name line

        getline(i, line);//types line

        for(auto s : split(line, ",;"))
        {
            cout << s << endl;
        }
        double d;

        cout << "line: " << line << endl;

        while(i.peek()!=EOF)
        {
            getline(i, line);
            cout << line << endl;
            auto h = split(line, ",");
            for (auto i: h) {
                cout << i << endl;
            }
            cout << "=========\n";
        }
    }
}

}

#endif // CVS_FORMAT_H
