/*
 * trainer.h
 *
 *  Created on: Mar 12, 2014
 *      Author: peixinho
 */

#ifndef TRAINER_H_
#define TRAINER_H_

#include <utils/distance.h>
#include <classifier/core/prototypes_strategy.h>
#include <classifier/core/training_strategy.h>

namespace opf{
/**\authors Alan Zanoni Peixinho apeixinho@studends.ic.unicamp.br
*\authors Luis Augusto Martins Pereria lmartins@ic.unicamb.br
* \version 1.0.0
*/

class Trainer {
public:
    //TO DO: mudar parametros para funcao de train
    Trainer(opf::Distance distance, PrototypesStrategy &prototypes, TrainingStrategy &trainer, Patterns &patterns);
    //TO DO: mudar nome da funcao
    virtual Model train() = 0;

private:
};

}
#endif /* TRAINER_H_ */
