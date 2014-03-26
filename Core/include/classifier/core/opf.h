/*
 * opf.h
 *
 *  Created on: Mar 4, 2014
 *      Author: tome
 */

#ifndef OPF_H_
#define OPF_H_

#include <classifier/core/model.h>
#include <classifier/core/trainer.h>
#include <utils/distance.h>
#include <classifier/core/classifier.h>

class OPF{
public:
    OPF(Trainer &trainer, Classifier &classifier, opf::Distance distance);
    void BuildModel(Patterns& training);
    int Predict(Patterns& test);
private:
    Model* opf_model_ = NULL;
};

#endif /* OPF_H_ */
