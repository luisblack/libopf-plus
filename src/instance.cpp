/*
 * instance.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */
#include "instance.h"

inline Instance::Instance(int numberOfFeatures) {
	features = new double[numberOfFeatures];
	this->numberOfFeatures = numberOfFeatures;
}

inline Instance::Instance(int classValue, double* features, int numberOfFeatures) {
	setClassValue(classValue);
	setFeatures(features);
	features = new double[numberOfFeatures];
	setNumberOfFeatures(numberOfFeatures);
}

inline Instance::~Instance(){
	delete features;
}

inline int Instance::getClassValue() const {
	return classValue;
}

inline void Instance::setClassValue(int classValue) {
	this->classValue = classValue;
}

inline double* Instance::getFeatures() const {
	return this->features;
}

inline void Instance::setFeatures(double* features) {
	for(int j=0; j < numberOfFeatures; j++) this->features[j] = features[j];
}

inline int Instance::getNumberOfFeatures() const {
	return numberOfFeatures;
}

inline void Instance::setNumberOfFeatures(int numberOfFeatures) {
	this->numberOfFeatures = numberOfFeatures;
}
