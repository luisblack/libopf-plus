#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <sstream>

namespace opf{

std::vector<std::string> &split(const std::string &s, string delimiters, std::vector<std::string> &elems) {
    std::string item;

    int pos = 0;
    for(;;)
    {
        int newpos = s.find_first_of(delimiters, pos+1);
        if(newpos == -1)
        {
            elems.push_back(s.substr(pos));
            break;
        }
        elems.push_back(s.substr(pos, newpos-pos));
        pos = newpos + 1;
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, string delimiters) {
    std::vector<std::string> elems;
    split(s, delimiters, elems);
    return elems;
}

}
#endif // STRING_UTILS_H
