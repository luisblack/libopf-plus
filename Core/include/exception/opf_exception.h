#ifndef OPF_EXCEPTION_H
#define OPF_EXCEPTION_H

#include <string>

using namespace std;

namespace opf {

class OPFException : exception
{
private:
    const string HEADER = "OPF Exception: ";
    string message_;
public:
    OPFException(string message);

    virtual const char* what() const throw();
};

}

#endif // OPF_EXCEPTION_H
