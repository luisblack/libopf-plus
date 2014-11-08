#include <exception/opf_exception.h>

opf::OPFException::OPFException(const std::string& message):message_(HEADER + message)
{
}

opf::OPFException::OPFException()
{

}

void opf::OPFException::set_message(const std::string& message)
{
    message_ = message;
}

const char* opf::OPFException::what() const throw()
{
    return message_.c_str();
}
