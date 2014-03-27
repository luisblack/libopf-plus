#ifndef TRAINING_STRATEGY_H
#define TRAINING_STRATEGY_H

#include<classifier/core/model.h>

/**Strategy interface for training. All new strategy of training must implement this interface.
*/

class TrainingStrategy
{
public:
    TrainingStrategy();

    /*define input and output parameters*/
    virtual Model* train();
};

#endif // TRAINING_STRATEGY_H
