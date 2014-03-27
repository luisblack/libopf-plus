#include<classifier/core/model.h>
#include<libopf-plus.h>

Model::Model(Patterns patterns){
    ordered_list_of_nodes_.capacity(patterns.get_number_of_patterns());
}

Model::Model(string file_name){
    load_model_from_file(file_name);
}

vector<int>Model::get_ordered_list_of_nodes()const{
    return ordered_list_of_nodes_;
}

void Model::push_ordered_list_of_nodes(int index){
    ordered_list_of_nodes_.push_back(index);
}

ModelNode* Model::pop_ordered_list_of_nodes(){
    return NULL;
}

iterator Model::begin(){
    return node.begin();
}

iterator Model::end(){
    return node.end();
}
