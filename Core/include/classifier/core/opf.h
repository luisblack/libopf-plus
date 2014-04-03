/*
 * opf.h
 *
 *  Created on: Mar 4, 2014
 *      Author: tome
 */

#include <utils/distance.h>
#include <classifier/core/model.h>
#include <classifier/core/prototypes_strategy.h>
#include <classifier/core/classifier.h>
#include <classifier/core/trainer.h>

#ifndef OPF_H_
#define OPF_H_

/**\authors Alan Zanoni Peixinho apeixinho@studends.ic.unicamp.br
*\authors Luis Augusto Martins Pereria lmartins@ic.unicamb.br
* \version 1.0.0
*/

class OPF{
public:
    OPF(Trainer &trainer, Classifier &classifier, opf::Distance distance);
    void BuildModel(Patterns& training);
    int Predict(Patterns& test);
private:
    Model* opf_model_ = NULL;
};

#endif /* OPF_H_ */
