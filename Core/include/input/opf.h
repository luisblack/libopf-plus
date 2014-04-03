#ifndef OPF_H
#define OPF_H

#include <iostream>
#include <input/patterns.h>

namespace opf {
namespace io {

    void opf(ostream& o, Patterns& p)
    {
        o << p;
    }

    void opf(istream& i, Patterns& p)
    {
        i >> p;
    }
}
}

#endif // OPF_H
