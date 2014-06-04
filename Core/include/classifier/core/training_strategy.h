#ifndef TRAINING_STRATEGY_H_
#define TRAINING_STRATEGY_H_

#include <classifier/core/model.h>
#include <classifier/complete_graph/mst_prototype.h>

namespace opf{

/**Interface for training strategies.
 * One may want to develop a new OPF training strategy.
 * Therefore, all new training strategy must implement this interface.
*/

class TrainingStrategy
{
public:
    TrainingStrategy()
    {}

    virtual Model train(opf::Distance distance, opf::Patterns patterns, MSTPrototypes& mst)=0;
    virtual ~TrainingStrategy() {}
};

}
#endif // TRAINING_STRATEGY_H_
