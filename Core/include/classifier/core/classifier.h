/*
 * classifier.h
 *
 *  Created on: Mar 12, 2014
 *      Author: peixinho
 */

#ifndef CLASSIFIER_H_
#define CLASSIFIER_H_

#include <utils/distance.h>
#include <classifier/core/classifying_strategy.h>

using namespace std;

class Classifier {
public:
    Classifier(Model &model, ClassifyingStrategy &classifier, Patterns &test_patterns);
    void set_distance(opf::Distance);
    opf::Distance distance();
	int Predict(Pattern pattern);
	int* Predict(Patterns patterns);

	private:
};

#endif /* CLASSIFIER_H_ */
