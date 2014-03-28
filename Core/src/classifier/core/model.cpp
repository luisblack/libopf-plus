#include<classifier/core/model.h>
#include<libopf-plus.h>

Model::Model(Patterns patterns){
    ordered_list_of_nodes_.reserve(patterns.get_number_of_patterns());
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

ModelNode* Model::pop_ordered_list_of_nodes() const{
    return NULL;
}

Model::const_iterator Model::begin() const{
    return node.begin();
}

Model::const_iterator Model::end() const{
    return node.end();
}
