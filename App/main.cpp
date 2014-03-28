#include <iostream>
#include <libopf-plus.h>


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
    Patterns p("boat.txt");

    auto aeho = opf::io::format_out(p, hue);

    cout << aeho << endl;

//    cout << opf::io::format_out(p, [](ostream& o, Patterns &p){cout << "aeho";});

//    int x, y;
//    PriorityQueue Q(5,PriorityQueue::Type::MAX);

//    Q.insert(0.1);
//    Q.insert(0.01);
//    Q.insert(0.5);
//    Q.insert(10);
//    Q.insert(1);
//    Q.sort();
//    for(const int *i = Q.begin(); i != Q.end(); ++i){
//        Q.update(*i,0.0);
//        cout <<Q.get_cost(*i)<<"\t";
//        cout <<*i<<endl;
//    }
    cout << p.get_number_of_patterns() << endl;
    cout << p.get_number_of_classes() << endl;

    return 0;
}

