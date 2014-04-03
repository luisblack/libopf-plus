#include <iostream>
#include <libopf-plus.h>

#include <input/csv_format.h>
#include <input/io_formater.h>

#include <fstream>


using namespace std;

void hue(ostream& o, Patterns& p)
{
    o << p.get_number_of_patterns() + p.get_number_of_classes();
}

void hue2(Patterns& p, ostream& o, opf::io::OutputMethod omg)
{
    omg(o,p);
}

int main()
{
    try
    {
        Patterns p(42);

        std::fstream f("iris.csv");

        if(!f.is_open())
        {
            cout << "Nao consigo abrir o aqrquivo wowow\n";
            return 1;
        }

        f >> opf::io::format(p, opf::input::csv);

        cout << p.get_number_of_patterns() << endl;
        cout << p.get_number_of_classes() << endl;

        return 0;
    }catch(opf::OPFException e)
    {
        cerr << e.what() << endl;
    }

}

