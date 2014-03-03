/*
 * instances.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */

#include "instances.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



inline Instances::Instances(char* fileName) {
	FILE *fp = fopen(fileName,"rb");


	if(fp == NULL){
		fprintf(stderr,"can't open input file %s\n",fileName);
		exit(1);
	}

	size_t result;
	int numberOfFeatures;
	result = fread(&numberOfInstances, sizeof(int), 1, fp);
	result = fread(&numberOfClasses, sizeof(int), 1, fp);
	result = fread(&numberOfFeatures, sizeof(int), 1, fp);
	instances = Instances[numberOfInstances];
}

inline Instances::Instances(int numberOfInstances) {
}

inline int Instances::getNumberOfInstances() const {
	return numberOfInstances;
}

inline void Instances::setNumberOfInstances(int numberOfInstances) {
	this->numberOfInstances = numberOfInstances;
}

inline int Instances::getNumberOfClasses() const {
	return numberOfClasses;
}

inline void Instances::setNumberOfClasses(int numberOfClasses) {
	this->numberOfClasses = numberOfClasses;
}
