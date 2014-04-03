#include "include/exception/lazy_programer_exception.h"

using namespace opf;

LazyProgramerException::LazyProgramerException(string message):OPFException(HEADER + message)
{
}
