
#include <classifier/complete_graph/mst_prototype.h>
#include <input/patterns.h>
#include <utils/priority_queue.h>
#include <limits>

MSTPrototypes::MSTPrototypes(){

}

vector<double> MSTPrototypes::SelectPrototypes(opf::Distance distance, Patterns patterns)
{
    int p;
    double weight;
    vector<double>initial_costs(patterns.get_number_of_patterns());
    vector<int>predecessors(patterns.get_number_of_patterns());
    vector<bool>status(patterns.get_number_of_patterns());
    PriorityQueue Q(patterns.get_number_of_patterns());

    for(int i=0; i < patterns.get_number_of_classes(); i++){
        Q.insert(numeric_limits<double>::max());
    }

    Q.update(0,0);
    predecessors[0] = NIL;

    while(!Q.empty()){
        Q.sort();
        p = Q.remove();

        //selecting prototypes
        if(predecessors[p] != NIL){
            if(patterns.pattern[p].get_class_value() != patterns.pattern[predecessors[p]].get_class_value()){
                if(status[p] != PROTOTYPE){
                    initial_costs[p] = 0.0;
                    status[p] = PROTOTYPE;
                }
            }

            if(status[predecessors[p]]!= PROTOTYPE){
                initial_costs[predecessors[p]] = 0.0;
                status[predecessors[p]] = PROTOTYPE;
            }
        }

        for(const int *q = Q.begin(); q != Q.end(); ++q){
            weight = distance(patterns.pattern[p].get_feature_vector(), patterns.pattern[*q].get_feature_vector());

            if(weight < Q.get_cost(*q)){
                Q.update(*q,weight);
                predecessors[*q] = p;
            }
        }
    }
    return initial_costs;
}
