/*
 * trainer.h
 *
 *  Created on: Mar 12, 2014
 *      Author: peixinho
 */

#ifndef TRAINER_H_
#define TRAINER_H_

#include <utils/distance.h>
#include <classifier/core/prototype_strategy.h>
#include <classifier/core/training_strategy.h>

class Trainer {
public:
    Trainer(opf::Distance distance, PrototypesStrategy &prototypes, TrainingStrategy &trainer, Patterns &patterns);
    virtual Model train() = 0;

private:
};

#endif /* TRAINER_H_ */
