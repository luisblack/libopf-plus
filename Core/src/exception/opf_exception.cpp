#include "include/exception/opf_exception.h"

using namespace opf;

OPFException::OPFException(const string& message):message_(HEADER + message)
{
}

OPFException::OPFException()
{

}

void OPFException::set_message(const string& message)
{
    message_ = message;
}

const char* OPFException::what() const throw()
{
    return message_.c_str();
}
