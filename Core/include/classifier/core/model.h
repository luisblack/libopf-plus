/*
 * opf_model.h
 *
 *  Created on: Mar 4, 2014
 *      Author: tome
 */

#ifndef MODEL_H_
#define MODEL_H_


#include<libopf-plus.h>
#include<classifier/core/model_node.h>
#include<iostream>



class Model{
public:
    vector<ModelNode>::iterator iterator;
    vector<ModelNode>::const_iterator const_iterator;


    //TO DO: valor ou referencia? salvar funcao de distnacia no model, é possivel?
    Model(Pattern pattern);

    /**Constructor for a model saved in file.
     * @param file_name name of a file whose model was saved in.
    */
    Model(string file_name);

    vector<int>get_ordered_list_of_nodes()const{
        return ordered_list_of_nodes_;
    }
    //TO DO: utilizar lista ou não
    void push_ordered_list_of_nodes(int index);

    ModelNode * pop_ordered_list_of_nodes()const;

    vector<ModelNode>::iterator begin()const;

    vector<ModelNode>::iterator end()const;

	//"save" method in C++ pattern
	std::ostream& operator>>(std::ostream& out);

    /**Save model to file. Model has to be completely filled.
    */
    void save_model_to_file();

private:
    vector<int> ordered_list_of_nodes_;
    vector<ModelNode> node;

    /**Loads model from file. File has to be saved using  the same sequence used by the method "save_model_to_file".
     * @see save_model_to_file
    */
    void load_model_from_file(string file_name);
};

#endif /* OPF_MODEL_H_ */
