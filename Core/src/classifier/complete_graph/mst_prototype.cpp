#include <classifier/complete_graph/mst_prototype.h>
#include <input/patterns.h>
#include <utils/priority_queue.h>
#include <limits>

MSTPrototypes::MSTPrototypes()
{

}

vector<double> MSTPrototypes::SelectPrototypes(opf::Distance distance, Patterns patterns)
{
    int p;
    double weight;

    //DUVIDA: inicializar vector com FLT_MAX
    initial_costs_ = vector<double>(patterns.get_number_of_patterns());
    predecessors_ = vector<int>(patterns.get_number_of_patterns());
    prototype_status_ = vector<bool>(patterns.get_number_of_patterns());
    PriorityQueue Q(patterns.get_number_of_patterns());

    for(int i=0; i < patterns.get_number_of_classes(); i++)
    {
        Q.insert(numeric_limits<double>::max());
    }

    Q.update(0,0);
    predecessors_[0] = NIL;

    //Prim's algorithm
    while(!Q.empty())
    {
        Q.sort();
        p = Q.remove();

        if(predecessors_[p] != NIL)
        {//selecting nodes as prototypes


            if(patterns.pattern[p].get_class_value() != patterns.pattern[predecessors_[p]].get_class_value())
            {//If p has different class value from its predecessor, then both have to be selected as prototypes.
            //Prototype nodes are assigned with initial cost equal to zero.

                if(prototype_status_[p] != PROTOTYPE)
                {//checking if p is already a prototype.
                    initial_costs_[p] = 0.0;
                    prototype_status_[p] = PROTOTYPE;
                }
            }

            if(prototype_status_[predecessors_[p]]!= PROTOTYPE)
            {//checking if the predecessor's node of p is already a prototype.
                initial_costs_[predecessors_[p]] = 0.0;
                prototype_status_[predecessors_[p]] = PROTOTYPE;
            }
        }//end

        for(const int *q = Q.begin(); q != Q.end(); ++q)
        {
            weight = distance(patterns.pattern[p].get_feature_vector(), patterns.pattern[*q].get_feature_vector());

            if(weight < Q.get_cost(*q))
            {
                Q.update(*q,weight);
                predecessors_[*q] = p;
            }
        }
    }
    return initial_costs_;
}
