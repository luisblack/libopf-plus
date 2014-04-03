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
    PriorityQueue Q(5);
try{
    Q.insert(0.5);
    Q.insert(0.2);
    Q.insert(0.3);
    Q.insert(0.01);
    Q.insert(10);

    Q.sort();
    for(int i: Q){
        cout<<i<<" "<<Q.get_cost(i)<<endl;
    }

    cout<<Q.remove()<<endl;

}catch(const char* e){
    cerr<< e;}
}

