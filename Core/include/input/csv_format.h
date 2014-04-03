#ifndef CVS_FORMAT_H
#define CVS_FORMAT_H

#include <iostream>
#include <input/patterns.h>
#include <input/pattern.h>
#include <exception/lazy_programer_exception.h>

#include <utils/string_utils.h>

#include <limits>

namespace opf {

namespace output {

    void csv(ostream& o, Patterns& p);

}

namespace input {

    void csv(istream& i, Patterns& p);
}

}

#endif // CVS_FORMAT_H
