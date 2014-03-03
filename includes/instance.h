/*
 * instance.h
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */

#ifndef INSTANCE_H_
#define INSTANCE_H_

class Instance{
public:
	Instance(int classValue, double* features, int numberOfFeatures);
	Instance(int numberOfFeatures);
	~Instance();
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



#endif /* INSTANCE_H_ */
