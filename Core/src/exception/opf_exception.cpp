#include "include/exception/opf_exception.h"

using namespace opf;

OPFException::OPFException(string message):message_(HEADER + message)
{
}

const char* OPFException::what() const throw()
{
    return message_.c_str();
}
