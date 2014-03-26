/*
 * opf_model.h
 *
 *  Created on: Mar 4, 2014
 *      Author: tome
 */

#ifndef MODEL_H_
#define MODEL_H_

#include<iostream>

class Model{
public:
	Model(int numberOfPatterns);
	void setPrototypeStatus(int index, bool status);
	bool getPrototypeStatus(int index) const;
	//"save" method in C++ pattern
	std::ostream& operator>>(std::ostream& out);

private:
	bool *prototypeStatus;

};

#endif /* OPF_MODEL_H_ */
