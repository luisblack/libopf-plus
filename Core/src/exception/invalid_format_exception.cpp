#include <exception/invalid_format_exception.h>

using namespace std;

namespace opf{

InvalidFormatException::InvalidFormatException(const string message):OPFException(HEADER + message)
{
}

}
