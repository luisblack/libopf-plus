#include <classifier/complete_graph/opf_training.h>
#include <classifier/complete_graph/mst_prototype.h>
#include <classifier/core/model.h>
#include <libopf-plus.h>
#include <cassert>

namespace opf {

OPFTraining::OPFTraining(){

}

OPFTraining::~OPFTraining()
{

}

Model OPFTraining::train(opf::Distance distance, Patterns patterns, MSTPrototypes& mst){
    double tmp;
    double weight;

    vector<double>initial_costs = mst.SelectPrototypes(distance, patterns);

    for (double d : initial_costs) {
        cout << "Initial: " << d << endl;
    }

    //DUVIDA: isso muda o valor do vector?
    PriorityQueue Q(initial_costs.size(), PriorityQueue::min_policy);

    for (double cost : initial_costs) {
        Q.insert(min(cost, 1000.0));
    }


    Model model(patterns, distance);

//    cout << "Start Train" << endl;

//    cout << Q.empty() << endl;

    while(!Q.empty()){

        Q.sort();
        auto p = Q.remove();

        cout << p.cost_ << endl;

        model.push_ordered_list_of_nodes(p.index_);
        model[p.index_].set_cost(p.cost_);

        cout << p.index_ << " --> " << model[p.index_].get_cost() << endl;

        assert(p.cost_ == model[p.index_].get_cost());

        //TO DO: mudar para um par com atributo index e cost
        for(PriorityQueue::const_iterator q = Q.begin(); q != Q.end(); ++q){

            //DUVIDA: como vamos passar a matriz de distâncias?
            weight = distance(model[p.index_].get_feature_vector(), model[q->index_].get_feature_vector());

            tmp = max(weight,p.cost_);
            if(weight < q->cost_){
                Q.update(q->index_, weight);
                model[q->index_].set_predecessor(p.index_);
                model[q->index_].set_class_value(model[p.index_].get_class_value());
            }
        }

    }

    return model;
}
}
