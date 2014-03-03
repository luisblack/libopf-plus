/*
 * instances.h
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */

#ifndef INSTANCES_H_
#define INSTANCES_H_

#include<string>

class Instances{
public:
	Instances(char* file_name);
	Instances(int numberOfInstances);
	int getNumberOfInstances() const;
	void setNumberOfInstances(int numberOfInstances);
	int getNumberOfClasses() const;
	void setNumberOfClasses(int numberOfClasses);

private:
	Instance *instances;
	int numberOfInstances;
	int numberOfClasses;
};




#endif /* INSTANCES_H_ */
