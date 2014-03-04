/*
 * opf.h
 *
 *  Created on: Mar 4, 2014
 *      Author: tome
 */

#ifndef OPF_H_
#define OPF_H_

#include "opf_model.h"

class OPF{
public:
	OPF();
	OPF_Model buildModel(Patterns training);
	int * predict(OPF_Model model, Patterns test);
private:
	void findPrototypes(Patterns training);
};

#endif /* OPF_H_ */
