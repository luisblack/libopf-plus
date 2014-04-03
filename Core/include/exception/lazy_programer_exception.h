#ifndef LAZY_PROGRAMER_EXCEPTION_H
#define LAZY_PROGRAMER_EXCEPTION_H

#include <exception/opf_exception.h>

using namespace std;
namespace opf {

class LazyProgramerException : public OPFException
{
private:
    const string HEADER = "Resource under implementation (don't blame me): ";
public:
    LazyProgramerException(const string& message);
};

}

#endif // LAZY_PROGRAMER_EXCEPTION_H
