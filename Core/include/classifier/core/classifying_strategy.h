#ifndef CLASSIFYING_STRATEGY_H
#define CLASSIFYING_STRATEGY_H

#include<input/patterns.h>
#include<classifier/core/model.h>
#include<vector>

/**Interface for classifying strategies.
* One may want to develop a new OPF classifying strategy.
* Thus, this class provides an interface to support this development.
* All new classifying strategies should implement this interface.
*\authors Alan Zanoni Peixinho apeixinho@studends.ic.unicamp.br
*\authors Luis Augusto Martins Pereria lmartins@ic.unicamb.br
* \version 1.0.0
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
