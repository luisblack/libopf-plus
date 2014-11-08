#ifndef LAZY_PROGRAMER_EXCEPTION_H
#define LAZY_PROGRAMER_EXCEPTION_H

#include <exception/opf_exception.h>

namespace opf {

class LazyProgramerException : public OPFException
{
private:
    const std::string HEADER = "Resource under implementation (don't blame me): ";
public:
    LazyProgramerException(const std::string& message);
};

}

#endif // LAZY_PROGRAMER_EXCEPTION_H
