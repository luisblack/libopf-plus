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

double euclidean_distance(const vector<double> v1, const vector<double> v2){
    double dist=0;
    for(int i=0; i < v1.size();i++){
        dist+=(v1[i]-v2[i])*(v1[i]-v2[i]);
    }
    return dist;
}

void ff(Distance dist){
    vector<double>v1;
    v1.push_back(1);
    v1.push_back(2);
}

int main()
{
//    OPFTraining opf;
    MSTPrototypes mst;
    Distance Dist = euclidean_distance;

    vector<double> v = {12,32,33};

    cout << v << endl;

    fstream fs;
    fs.open("boat.txt");

    Patterns patterns;
    fs>>patterns;
//    ff(Dist);
//    vector<double> v = mst.SelectPrototypes(Dist, patterns);

//    cout << "\n\n============\n\n";
//    int i=0;
//    for (double d : v) {
//        if(d==0)
//        {
//            cout << i << endl;
//        }
//        i++;
//    }

    OPFTraining training;

    auto hue = [](const vector<double> v, const vector<double> x) {return euclidean_distance(v,x);};
    Model m = training.train(euclidean_distance, patterns, mst);

    for (auto it = m.ordered_begin(); it!=m.ordered_end(); ++it) {
        //cout << it.index_[it.cur_idx_] << endl;
        cout << *it;
    }

    OPFClassifying classifier;

    vector<double> out = classifier.classify(m, patterns);

    cout << out << endl;
    cout << m.end() - m.begin() << endl;

//    for (ModelNode i : m) {
//        cout << i.get_cost() << endl;
//    }

    //opf.train(distance,patterns);
}
