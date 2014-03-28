#include<classifier/complete_graph/opf_training.h>
#include<classifier/complete_graph/mst_prototype.h>
#include<classifier/core/model.h>
#include<libopf-plus.h>

OPFTraining::OPFTraining(){

}

Model* OPFTraining::train(opf::Distance distance, Patterns patterns){
    int p,q;
    double tmp;

    /*
    vector<double>initial_costs = MSTPrototypes.SelectPrototypes(distance, patterns);

    PriorityQueue Q(patterns.get_number_of_patterns());
    Q.set_costs(initial_costs);

    Model model_train(patterns);

    while(!Q.empty()){
        Q.sort();// what if does heap is empty?
        p = Q.remove();
        model_train.push_ordered_list_of_nodes(p);
        model_train.node.set_cost(Q.get_cost(p));

        for(const int *q = Q.begin(); q != Q.end(); ++q){
            weight = distance(model_train.node[p].get_feature_vector(), model_train.node[*q].get_feature_vector());
            tmp = max(weight,Q.get_cost(p));

            if(weight < Q.get_cost(*q)){
                Q.update(*q, weight);
                model_train.node.set_predecessor(*q, p);
                model_train.node.set_class_value(q, model_train.node.get_class_value(p));
            }
        }
    }
    return model_train;
    */
}
