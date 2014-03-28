#include <iostream>
#include <libopf-plus.h>


using namespace std;

int main()
{
    Patterns p("boat.txt");

    int x, y;
    PriorityQueue Q(5,PriorityQueue::Type::MAX);

    Q.insert(0.1);
    Q.insert(0.01);
    Q.insert(0.5);
    Q.insert(10);
    Q.insert(1);
    Q.sort();
    for(const int *i = Q.begin(); i != Q.end(); ++i){
        Q.update(*i,0.0);
        cout <<Q.get_cost(*i)<<"\t";
        cout <<*i<<endl;
    }
    cout << p.get_number_of_patterns() << endl;
    cout << p.get_number_of_classes() << endl;

    return 0;
}

