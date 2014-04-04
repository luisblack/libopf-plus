#include <iostream>
#include <libopf-plus.h>

#include <input/csv_format.h>
#include <input/io_formater.h>

#include <fstream>


using namespace std;
using namespace opf;

void hue(ostream& o, Patterns& p)
{
    o << p.get_number_of_patterns() + p.get_number_of_classes();
}

void hue2(Patterns& p, ostream& o, opf::output::OutputMethod omg)
{
    omg(o,p);
}

int main()
{
    PriorityQueue Q(5, PriorityQueue::min_policy);

try{

    Q.insert(0.5);
    Q.insert(0.2);
    Q.insert(0.3);
    Q.insert(0.01);
    Q.insert(10);

    Q.sort();
    for(auto i: Q){
        cout<< i.index_ << " " << i.cost_ <<endl;
    }

    while(!Q.empty())
    {
        cout << "================" << endl;
        auto r = Q.remove();
        Q.sort();

        cout << "remove " << r.index_ << endl;

        for(auto i : Q)
        {
            cout << i.index_ << "  ++++++++++++++++++ ";
            Q.update(i.index_, r.cost_);
            cout << i.index_ << " " << i.cost_ << " " << Q.get_cost(i.index_) << endl;
        }

        cout << "---------------- ";

        cout<< r.index_ << " " << r.cost_ <<endl;
    }

}catch(OPFException e){
    cerr<< e.what() << endl;
}

}
