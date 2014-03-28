#include <input/io_formater.h>

namespace opf
{

    namespace io
    {

    InputFormatter::InputFormatter(Patterns &patterns, InputMethod &input_function)
        :patterns_(patterns), input_function_(input_function)
    {
    }


    istream& operator >>(istream& input, InputFormatter & input_formatter)
    {
        input_formatter.input_function_(input, input_formatter.patterns_);
        return input;
    }


    OutputFormatter::OutputFormatter(Patterns &patterns, OutputMethod &output_function)
        :patterns_(patterns), output_function_(output_function)
    {

    }

    ostream& operator <<(ostream& output, OutputFormatter & output_formatter)
    {
        output_formatter.output_function_(output, output_formatter.patterns_);
        return output;
    }


    InputFormatter& format(Patterns& patterns, InputMethod& input_method)
    {
        InputFormatter formatter(patterns, input_method);
        return formatter;
    }

    OutputFormatter& format(Patterns& patterns, OutputMethod& output_method)
    {
        OutputFormatter formatter(patterns, output_method);
        return formatter;
    }

    }
}
