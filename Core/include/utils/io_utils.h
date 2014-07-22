#ifndef IO_UTILS_H
#define IO_UTILS_H

#include<vector>
#include<iostream>

namespace opf
{

/**
 * Print a generic array
 */
template<typename T> std::ostream& operator<<(std::ostream& o, std::vector<T> v)
{
    o << "[";
    int i = 0;
    for(T t : v)
    {
        if(i>0)
            o << ", ";
        o << t;
        i++;
    }
    o << "]";
    return o;
}
}
#endif // IO_UTILS_H
