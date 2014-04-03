#include <classifier/complete_graph/opf_training.h>
#include <classifier/complete_graph/mst_prototype.h>
#include <classifier/core/model.h>
#include <libopf-plus.h>

namespace opf {



OPFTraining::OPFTraining(){

}

Model OPFTraining::train(opf::Distance distance, Patterns patterns, MSTPrototypes mst){
    int p;
    double tmp;
    double weight;

    vector<double>initial_costs = mst.SelectPrototypes(distance, patterns);

    //DUVIDA: isso muda o valor do vector?
    PriorityQueue Q(initial_costs.begin(),initial_costs.end(),PriorityQueue::Type::MIN);


    Model model(patterns, distance);

    while(!Q.empty()){
        //Q.sort();
        p = Q.remove();
        model.push_ordered_list_of_nodes(p);
        model[p].set_cost(Q.get_cost(p));

        //TO DO: mudar para um par com atributo index e cost
        for(PriorityQueue::const_iterator q = Q.begin(); q != Q.end(); ++q){

            //DUVIDA: como vamos passar a matriz de distâncias?
            weight = distance(model[p].get_feature_vector(), model[*q].get_feature_vector());

            tmp = max(weight,Q.get_cost(p));

            if(weight < Q.get_cost(*q)){
                Q.update(*q, weight);
                model[*q].set_predecessor(p);
                model[*q].set_class_value(model[p].get_class_value());
            }
        }
    }

    return model;
}
}
