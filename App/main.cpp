#include <iostream>
#include <libopf-plus.h>

using namespace std;

int main()
{
    Patterns p(42);

    int x, y;

    cin >> x >> y;

    cout << x << ", " <<  y << endl;

    CsvAdapter csv(p);

    cin >> csv;

    cout << p.get_number_of_patterns() << endl;
    cout << p.get_number_of_classes() << endl;

    return 0;
}

