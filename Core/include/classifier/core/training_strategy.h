#ifndef TRAINING_STRATEGY_H
#define TRAINING_STRATEGY_H

#include<classifier/core/model.h>

class TrainingStrategy
{
public:
    TrainingStrategy();
    /*define input and output parameters*/
    virtual Model* train();
};

#endif // TRAINING_STRATEGY_H
