#ifndef CLASSIFYING_STRATEGY_H
#define CLASSIFYING_STRATEGY_H

#include<input/patterns.h>
#include<classifier/core/model.h>
#include<vector>

class ClassifyingStrategy
{
public:
    ClassifyingStrategy();

    /*Define input and output parameters*/
    virtual vector<double> predict(Model training_model, Patterns test_patterns);
private:
};

#endif // CLASSIFIERSTRATEGY_H
