/*
 * instance.h
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */

#ifndef PATTERN_H_
#define PATTERN_H_

class Pattern{
public:
	Pattern(int classValue, double* features, int numberOfFeatures);
	Pattern(int numberOfFeatures);
	~Pattern();
	int getClassValue() const;
	void setClassValue(int classValue);
	double* getFeatures() const;
	void setFeatures(double *features);
	int getNumberOfFeatures() const;
	void setNumberOfFeatures(int numberOfFeatures);
	
private:
	int classValue;
	double *features;
	int numberOfFeatures;
};



#endif /* PATTERN_H_ */
