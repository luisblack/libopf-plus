#include "include/exception/lazy_programer_exception.h"

using namespace opf;

LazyProgramerException::LazyProgramerException(const string& message)
{
    set_message(HEADER + message);
}
