#ifndef INVALIDFORMATEXCEPTION_H
#define INVALIDFORMATEXCEPTION_H

#include <exception/opf_exception.h>

namespace opf
{

class InvalidFormatException : public OPFException
{
    const std::string HEADER = "InvalidFormatException: ";
public:
    InvalidFormatException(const std::string message);
};

}

#endif // INVALIDFORMATEXCEPTION_H
