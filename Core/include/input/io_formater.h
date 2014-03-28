#include <iostream>
#include <input/patterns.h>
#include <functional>

#ifndef FILE_FORMATS_H
#define FILE_FORMATS_H

using namespace std;

namespace opf {

    namespace io {

        typedef function<void(istream&, Patterns&)> InputMethod;
        typedef function<void(ostream&, Patterns&)> OutputMethod;

        class InputFormatter
        {
        public:
            Patterns& patterns_;
            InputMethod& input_function_;
            InputFormatter(Patterns&, InputMethod&);

        //    friend ostream& operator <<(ostream&, OutputFunction&);
            friend istream& operator >>(istream&, InputMethod&);
        };

        class OutputFormatter
        {
        public:
            Patterns& patterns_;
            OutputMethod& output_function_;
            OutputFormatter(Patterns&, OutputMethod&);

            friend ostream& operator <<(ostream&, OutputMethod&);
        //    friend istream& operator >>(istream&, InputFunction&);
        };


        InputFormatter& format(Patterns& patterns, InputMethod& input_method);
        OutputFormatter& format(Patterns& patterns, OutputMethod& output_method);

    }
}

#endif // FILE_FORMATS_H
