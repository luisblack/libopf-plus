/*
 * opf_training.h
 *
 *  Created on: Mar 21, 2014
 *      Author: luis
 */

#ifndef OPF_TRAINING_H_
#define OPF_TRAINING_H_

#include <classifier/core/training_strategy.h>
#include <utils/distance.h>
#include <input/patterns.h>
#include <classifier/complete_graph/mst_prototype.h>

namespace opf{
/**\authors Alan Zanoni Peixinho apeixinho@studends.ic.unicamp.br
*\authors Luis Augusto Martins Pereria lmartins@ic.unicamb.br
* \version 1.0.0
*/

class OPFTraining: public TrainingStrategy{
public:
	OPFTraining();
    virtual Model train(opf::Distance distance, Patterns patterns, MSTPrototypes mst);
private:
};

}

#endif /* OPF_TRAINING_H_ */
