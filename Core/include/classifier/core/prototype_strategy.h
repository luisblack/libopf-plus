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
#include <libopf-plus.h>

#include <vector>

using namespace std;

class PrototypesStrategy {
    public:
    virtual vector<double> SelectPrototypes(opf::Distance distance, Patterns patterns) = 0;
	private:
};

#endif //PROTOTYPES_ESTRATEGY_H_
