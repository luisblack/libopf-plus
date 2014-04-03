/*
 * opf_model.h
 *
 *  Created on: Mar 4, 2014
 *      Author: tome
 */

#ifndef MODEL_H_
#define MODEL_H_

#include <classifier/core/model_node.h>
#include <input/patterns.h>

/**Class for handling the training model informations.
 * This class provides attributes and methods to deal with information arising from training process that will be used on classifying process.
 *Among the informations that model can handle are: cost paths, set of pattern using in training phase, learned class value, predecessor of a node and so on.
 * \authors Alan Zanoni Peixinho apeixinho@studends.ic.unicamp.br
*\authors Luis Augusto Martins Pereria lmartins@ic.unicamb.br
* \version 1.0.0
*/

class Model{
public:
    typedef vector<ModelNode>::iterator iterator;
    typedef vector<ModelNode>::const_iterator const_iterator;


    //TO DO: valor ou referencia? salvar funcao de distancia no model, é possivel?
    Model(Patterns& pattern);

    /**Constructor for a model saved in file.
     * @param file_name name of a file whose model was saved in.
    */
    Model(const string& file_name);

    vector<int>get_ordered_list_of_nodes() const;
    //TO DO: utilizar lista ou não
    void push_ordered_list_of_nodes(int index);

    ModelNode& pop_ordered_list_of_nodes()const;

    Model::iterator begin();
    Model::iterator end();

    double distance(const vector<double>& v1, const vector<double>& v2)
    {
        return 0.0;
    }
	//"save" method in C++ pattern
	std::ostream& operator>>(std::ostream& out);

    /**Save model to file. Model has to be completely filled.
    */
    void save_model_to_file();

    ModelNode& operator[](int index)
    {
        return node_[index];
    }

private:
    vector<int> ordered_list_of_nodes_;
    vector<ModelNode> node_;

    /**Loads a model from file. File has to be saved using save_model_to_file.
     * @see save_model_to_file
    */
    void load_model_from_file(string file_name);
};

#endif /* OPF_MODEL_H_ */
