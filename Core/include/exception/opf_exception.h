#ifndef OPF_EXCEPTION_H
#define OPF_EXCEPTION_H

#include <string>

namespace opf {

class OPFException : std::exception
{
private:
    const std::string HEADER = "OPF Exception: ";
    std::string message_;
public:
    OPFException();
    OPFException(const std::string& message);

    void set_message(const std::string&);

    virtual const char* what() const throw();
};

}

#endif // OPF_EXCEPTION_H
