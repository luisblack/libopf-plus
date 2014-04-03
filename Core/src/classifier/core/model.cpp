#include<classifier/core/model.h>
#include<libopf-plus.h>

namespace opf{

    Model::Model(Patterns& patterns, Distance& distance):ordered_list_of_nodes_(patterns.get_number_of_patterns()),distance(distance){

    }

    Model::Model(const string& file_name){
        load_model_from_file(file_name);
    }

    void Model::push_ordered_list_of_nodes(int index){
        ordered_list_of_nodes_.push_back(index);
    }

    ModelNode& Model::pop_ordered_list_of_nodes() const{
        ModelNode node;
        return node;
    }

    Model::iterator Model::begin(){
        return node_.begin();
    }

    Model::iterator Model::end(){
        return node_.end();

    }
}
