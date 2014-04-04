#include<classifier/core/model_node.h>

namespace opf{

ModelNode::ModelNode()
{}

double ModelNode::get_cost() const{
    return cost_;
}

void ModelNode::set_cost(double cost){
    cost_ = cost;
}

int ModelNode::get_predecessor() const{
    return predecessor_;
}

void ModelNode::set_predecessor(int predecessor){
    predecessor_ = predecessor;
}

}
