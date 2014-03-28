/*
 * prototyper.h
 *
 *  Created on: Mar 12, 2014
 *      Author: peixinho
 */

#ifndef PROTOTYPES_ESTRATEGY_H_
#define PROTOTYPES_ESTRATEGY_H_

#include <input/pattern.h>
#include <input/patterns.h>
#include <utils/distance.h>

#include <vector>


/**Strategy interface of way to select prototypes. All new strategy of selecting prototypes must implement this interface.
*/
class PrototypesStrategy {
    public:
    /**Returns a vector with initial costs to all nodes.
     *These costs are used to define roots/prototypes in the process of growing optimum-path trees during OPF training phase.
     *@param distance a similarity function.
     *@param patterns set of input patterns.
     * @see MSTPrototypes
    */
    virtual vector<double> SelectPrototypes(opf::Distance distance, Patterns patterns) = 0;
	private:
};

#endif //PROTOTYPES_ESTRATEGY_H_
