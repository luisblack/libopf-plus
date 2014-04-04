#include <iostream>
#include <input/patterns.h>
#include <functional>

#ifndef FILE_FORMATS_H
#define FILE_FORMATS_H

using namespace std;

namespace opf {

    namespace input {

        class InputFormatter
        {

        public:
            Patterns& patterns_;
            InputMethod input_function_;
            InputFormatter(Patterns&, InputMethod);

            friend istream& operator >>(istream&, InputFormatter&);

        };

        InputFormatter& format(Patterns& patterns, InputMethod input_method);
    }

    namespace output {

        class OutputFormatter
        {
        public:
            Patterns& patterns_;
            OutputMethod& output_function_;
            OutputFormatter(Patterns&, OutputMethod&);

            friend ostream& operator <<(ostream&, OutputFormatter&);
        };

        OutputFormatter& format(Patterns& patterns, OutputMethod output_method);
    }
}

#endif // FILE_FORMATS_H
