#include <input/io_formater.h>

namespace opf
{

    namespace input
    {

    InputFormatter::InputFormatter(Patterns &patterns, InputMethod input_function)
        :patterns_(patterns), input_function_(input_function)
    {
    }


    istream& operator >>(istream& input, InputFormatter &input_formatter)
    {
        input_formatter.input_function_(input, input_formatter.patterns_);
        return input;
    }

    //cant be called in parallel, overwites values
    //to call in parallel, you should instantiate different copies of InputFormatter object
    InputFormatter& format(Patterns& patterns, InputMethod input_method)
    {
        static InputFormatter formatter(patterns, input_method);
        return formatter;
    }

    }

    namespace output
    {


    OutputFormatter::OutputFormatter(Patterns &patterns, OutputMethod& output_function)
        :patterns_(patterns), output_function_(output_function)
    {

    }

    ostream& operator <<(ostream& output, OutputFormatter & output_formatter)
    {
        output_formatter.output_function_(output, output_formatter.patterns_);
        return output;
    }


    //cant be called in parallel, overwites values
    //to call in parallel, you should instantiate different copies of OutputFormatter object
    OutputFormatter& format_out(Patterns& patterns, OutputMethod output_method)
    {
        static OutputFormatter formatter(patterns, output_method);
        return formatter;
    }

    }
}
