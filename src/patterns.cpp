/*
 * patterns.cpp
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */

#include "patterns.h"

/*Constructor creating an set of patterns from a dataset file with defined extension
 * param fileName - name of dataset file
 * */
inline Patterns::Patterns(string fileName) {

	string extention = fileName.substr(fileName.find_last_of(".") + 1);

	switch (extention){
		case LibOPF_EXTENSION:
			readFromLibOPF_Extension(fileName);
		default:
			fprintf(stderr,"%s is an invalid extension",extention);
			exit(1);
	}
}

/*Constructor creating an empty set of patterns with defined size
 * param numberOfPatterns - number of patterns to be allocated
 * */
inline Patterns::Patterns(int numberOfPatterns) {
	setNumberOfPatterns(numberOfPatterns);
	patterns = Patterns[numberOfPatterns];
}

inline Patterns::~Patterns(){
	for(int i; i < numberOfPatterns; i++) patterns[i].~Pattern();
}

/*Returns the number of patterns*/
inline int Patterns::getNumberOfPatterns() const {
	return numberOfPatterns;
}

/*Sets the number of patterns
 * param numberOfPatterns - number of patterns to be set */
inline void Patterns::setNumberOfPatterns(int numberOfPatterns) {
	this->numberOfPatterns = numberOfPatterns;
}

/*Returns the number of classes*/
inline int Patterns::getNumberOfClasses() const {
	return numberOfClasses;
}

/*Sets the number of classes
 * param numberOfClasses - number of classes to be set */
inline void Patterns::setNumberOfClasses(int numberOfClasses) {
	this->numberOfClasses = numberOfClasses;
}

/*Reads a file from LibOPF extension
 * param fileName - the file name
 * */
inline void Patterns::readFromLibOPF_Extension(string fileName){
	size_t result;
	int numberOfFeatures;
	int index, class_value;
	patterns = Patterns[numberOfPatterns];

	FILE *fp = fopen((char*)fileName,"rb");

	if(fp == NULL){
		fprintf(stderr,"can't open input file %s\n",fileName);
		exit(1);
	}

	result = fread(&numberOfPatterns, sizeof(int), 1, fp);
	result = fread(&numberOfClasses, sizeof(int), 1, fp);
	result = fread(&numberOfFeatures, sizeof(int), 1, fp);


	for(int i; i < numberOfPatterns; i++){
		result = fread(&index, sizeof(int), 1, fp);
		result = fread(&class_value, sizeof(int), 1, fp);
		double *featureVector = (double*)malloc(sizeof(double)*numberOfFeatures);

		for(int j=0; j < numberOfFeatures; j++)	result = fread(&featureVector[j], sizeof(int), 1, fp);

		patterns[i] = new Pattern(class_value,featureVector,numberOfFeatures);
	}
}
