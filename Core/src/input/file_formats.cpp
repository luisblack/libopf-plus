#include <input/file_formats.h>

CsvAdapter::CsvAdapter(Patterns &patterns):patterns_(patterns)
{
    cout << "chamei o manolo aqui" << endl;
}

istream& operator>>(istream &in, CsvAdapter &c)
{

    cout << "aehoooo" << endl;

    char comma;

    int samples_number;
    in >> samples_number;

    int val;

    in >> val;
    cout << val << endl;
    comma = in.get();
    cout << comma << endl;
    c.patterns_.set_number_of_classes(val);
    in >> val;
    comma = in.get();
    c.patterns_.set_number_of_patterns(val);

    cout << "wrapper.patterns( samples= " << samples_number << ", classes= " << c.patterns_.get_number_of_classes() << ", features= " << c.patterns_.get_number_of_patterns() << ")\n";

    c.patterns_.pattern = vector<Pattern>(samples_number);

    for(int i=0; i<samples_number; ++i)
    {
        Pattern&p = c.patterns_.pattern[i];
        p.set_dimension(c.patterns_.get_number_of_patterns());
        //in >> p;
    }

    return in;
}

//istream& csv(istream& in, Pattern& pattern)
//{
//    char comma;
//    int val;
//    in >> val;
//    pattern.set_index(val);
//    cout << pattern.get_index() << endl;
//    comma = in.get();
//    in >> val;
//    pattern.set_class_value(val);
//    comma = in.get();
//    cout << pattern.get_class_value() << endl;

//    double *array = new double[pattern.get_dimension()];
//    for (int j = 0; j < pattern.get_dimension(); ++j) {
//        cin >> array[j];
//        comma = in.get();
//    }

//    pattern.set_feature_vector(array, array+pattern.get_dimension());

//    return in;
//}
