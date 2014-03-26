#ifndef FILE_FORMATS_H
#define FILE_FORMATS_H

#include <iostream>
#include <input/patterns.h>

using namespace std;


//TO DO: Deixar mais bonito :p
class CsvAdapter
{
private:
    Patterns& patterns_;
public:
    CsvAdapter(Patterns& patterns);
    friend istream& operator>>(istream& in, CsvAdapter& c);
};

#endif // FILE_FORMATS_H
