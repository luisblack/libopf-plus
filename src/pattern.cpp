/*
 * Pattern.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */
#include "Pattern.h"

inline Pattern::Pattern(int numberOfFeatures) {
	features = new double[numberOfFeatures];
	this->numberOfFeatures = numberOfFeatures;
}

inline Pattern::Pattern(int classValue, double* features, int numberOfFeatures) {
	setClassValue(classValue);
	setFeatures(features);
	features = new double[numberOfFeatures];
	setNumberOfFeatures(numberOfFeatures);
}

inline Pattern::~Pattern(){
	delete features;
}

inline int Pattern::getClassValue() const {
	return classValue;
}

inline void Pattern::setClassValue(int classValue) {
	this->classValue = classValue;
}

inline double* Pattern::getFeatures() const {
	return this->features;
}

inline void Pattern::setFeatures(double* features) {
	for(int j=0; j < numberOfFeatures; j++) this->features[j] = features[j];
}

inline int Pattern::getNumberOfFeatures() const {
	return numberOfFeatures;
}

inline void Pattern::setNumberOfFeatures(int numberOfFeatures) {
	this->numberOfFeatures = numberOfFeatures;
}
