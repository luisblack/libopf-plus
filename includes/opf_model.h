/*
 * opf_model.h
 *
 *  Created on: Mar 4, 2014
 *      Author: tome
 */

#ifndef OPF_MODEL_H_
#define OPF_MODEL_H_

class OPF_Model{
public:
	OPF_Model(int numberOfPatterns);
	void setPrototypeStatus(int index, bool status);
	bool getPrototypeStatus(int index) const;
	void saveModel() const;

private:
	bool *prototypeStatus;

};

#endif /* OPF_MODEL_H_ */
