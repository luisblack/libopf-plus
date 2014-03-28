#ifndef CLASSIFYING_STRATEGY_H
#define CLASSIFYING_STRATEGY_H

#include<input/patterns.h>
#include<classifier/core/model.h>
#include<vector>

/**Strategy interface of classifying. All new strategy of classifying must implement this interface.
*/

class ClassifyingStrategy
{
public:
    ClassifyingStrategy();

    /**Returns a vector with predicted class values for all pattern in the set test.
     * Predicted class values are placed into the vector following the same order of patterns in test set.
     *@param model a training model
     *@test test set of patterns.
     * @see OPFClassifying
     */
    virtual vector<double> classify(Model model, Patterns test);
private:
};

#endif // CLASSIFIERSTRATEGY_H
