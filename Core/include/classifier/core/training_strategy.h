#ifndef TRAINING_STRATEGY_H_
#define TRAINING_STRATEGY_H_

#include <classifier/core/model.h>

namespace opf{

/**Interface for training strategies.
 * One may want to develop a new OPF training strategy.
 * Therefore, all new training strategy must implement this interface.
*/

class TrainingStrategy
{
public:
    TrainingStrategy();

    /*define input and output parameters*/
    virtual Model* train();
};

}
#endif // TRAINING_STRATEGY_H_
