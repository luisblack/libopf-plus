#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <sstream>
#include <vector>
#include <string>

namespace opf{

std::vector<std::string> &split(const std::string &s, const std::string delimiters, std::vector<std::string> &elems);

std::vector<std::string> split(const std::string &s, const std::string delimiters);

}
#endif // STRING_UTILS_H
