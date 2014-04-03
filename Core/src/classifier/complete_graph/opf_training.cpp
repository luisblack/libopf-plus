#include <classifier/complete_graph/opf_training.h>
#include <classifier/complete_graph/mst_prototype.h>
#include <classifier/core/model.h>
#include <libopf-plus.h>

OPFTraining::OPFTraining(){

}

Model OPFTraining::train(opf::Distance distance, Patterns patterns){
    int p;
    double tmp;
    double weight;

    //vector<double>initial_costs = MSTPrototypes::SelectPrototypes(distance, patterns);

    vector<double> initial_costs(20);

    //DUVIDA: isso muda o valor do vector?
    PriorityQueue Q(initial_costs.begin(),initial_costs.end(),PriorityQueue::Type::MIN);

    //DUVIDA: patterns duas vezes na memória. tb passar a distância utilizada para o model
    Model model(patterns);

    while(!Q.empty()){
        Q.sort();// DUVIDA: e se a heap estiver vazia
        p = Q.remove();
        model.push_ordered_list_of_nodes(p);
        model[p].set_cost(Q.get_cost(p));

        //TO DO: mudar para um par com atributo index e cost
        for(const int *q = Q.begin(); q != Q.end(); ++q){

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
