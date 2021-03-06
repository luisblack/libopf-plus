#include<classifier/core/model.h>
#include<libopf-plus.h>
#include<utils/indexed_iterator.h>

namespace opf{

    Model::Model(Patterns& patterns, Distance& distance):ordered_list_of_nodes_(patterns.get_number_of_patterns()),distance(distance),node_(patterns.get_number_of_patterns()),
        cur_push_idx_(0), cur_pop_idx_(0){

    }

    Model::Model(const string& file_name){
        load_model_from_file(file_name);
    }

    void Model::push_ordered_list_of_nodes(int index){
        ordered_list_of_nodes_[cur_push_idx_] = index;
        cur_push_idx_++;
    }

    vector<int> Model::get_ordered_list_of_nodes() const
    {
        return ordered_list_of_nodes_;
    }

    ModelNode& Model::pop_ordered_list_of_nodes(){

        if(cur_pop_idx_>=cur_push_idx_)
        {
            throw OPFException("The list is already empty!, bro!!");
        }

        int index = ordered_list_of_nodes_[cur_pop_idx_];
        cur_pop_idx_++;

        return node_[index];
    }

    Model::iterator Model::begin(){
        return node_.begin();
    }

    Model::iterator Model::end(){
        return node_.end();
    }

    IndexedIterator<ModelNode> Model::ordered_begin()
    {
        return IndexedIterator<ModelNode>::begin(node_, ordered_list_of_nodes_);
    }

    IndexedIterator<ModelNode> Model::ordered_end()
    {
        return IndexedIterator<ModelNode>::end(node_, ordered_list_of_nodes_);
    }

    void Model::load_model_from_file(const string filename)
    {
    }

    void Model::save_model_to_file(const string filename)
    {
    }
}
