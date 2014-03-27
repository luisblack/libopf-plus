/*
 * opf_training.h
 *
 *  Created on: Mar 21, 2014
 *      Author: luis
 */

#ifndef OPF_TRAINING_H_
#define OPF_TRAINING_H_

#include<classifier/core/training_strategy.h>
#include<utils/distance.h>
#include <input/patterns.h>

class OPFTraining: public TrainingStrategy{
public:
	OPFTraining();
   virtual Model* train(opf::Distance distance, Patterns patterns);
private:
};



#endif /* OPF_TRAINING_H_ */
