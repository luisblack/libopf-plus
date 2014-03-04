/*
 * patterns.h
 *
 *  Created on: Mar 3, 2014
 *      Author: tome
 */

#ifndef PATTERNS_H_
#define PATTERNS_H_

#include<string>
using namespace std;

class Patterns{
public:
	Patterns(string fileName);
	Patterns(int numberOfPatterns);
	~Patterns();
	int getNumberOfPatterns() const;
	void setNumberOfPatterns(int numberOfPatterns);
	int getNumberOfClasses() const;
	void setNumberOfClasses(int numberOfClasses);

private:
	static string LibOPF_EXTENSION = "opf";
	Pattern *patterns;
	int numberOfPatterns;
	int numberOfClasses;
	void readFromLibOPF_Extension(string fileName);
};




#endif /* INSTANCES_H_ */
