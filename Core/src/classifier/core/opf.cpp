#include <classifier/core/opf.h>
#include <iostream>

OPF::OPF(Trainer &trainer, Classifier &classifier, opf::Distance distance)
{
    cout << "Criei um opf marotors";
}

void OPF::BuildModel(Patterns &training)
{
    //TO DO: criar model e guardar em uma variavel
}

int OPF::Predict(Patterns &test)
{

}
