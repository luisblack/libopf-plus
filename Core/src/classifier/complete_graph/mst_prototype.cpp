#include <classifier/complete_graph/mst_prototype.h>
#include <input/patterns.h>
#include <utils/priority_queue.h>
#include <limits>

using namespace opf;

MSTPrototypes::MSTPrototypes()
{

}

vector<double> MSTPrototypes::SelectPrototypes(opf::Distance distance, opf::Patterns &patterns)
{
    double weight;

    //DUVIDA: inicializar vector com FLT_MAX
    initial_costs_ = vector<double>(patterns.get_number_of_patterns(), numeric_limits<double>::max());
    predecessors_ = vector<int>(patterns.get_number_of_patterns());
    prototype_status_ = vector<bool>(patterns.get_number_of_patterns());

    PriorityQueue Q(patterns.get_number_of_patterns());

    for(int i=0; i < patterns.get_number_of_patterns(); i++)
    {
        Q.insert(numeric_limits<double>::max());
    }

    Q.update(0,0);
    predecessors_[0] = NIL;

    //Prim's algorithm
    while(!Q.empty())
    {
        Q.sort();
        auto p = Q.remove();

        if(predecessors_[p.index_] != NIL)
        {//selecting nodes as prototypes


            if(patterns.pattern[p.index_].get_class_value() != patterns.pattern[predecessors_[p.index_]].get_class_value())
            {//If p has different class value from its predecessor, then both have to be selected as prototypes.
            //Prototype nodes are assigned with initial cost equal to zero.

                if(prototype_status_[p.index_] != PROTOTYPE)
                {//checking if p is already a prototype.
                    initial_costs_[p.index_] = 0.0;
                    prototype_status_[p.index_] = PROTOTYPE;
                }

                if(prototype_status_[predecessors_[p.index_]]!= PROTOTYPE)
                {//checking if the predecessor's node of p is already a prototype.
                    initial_costs_[predecessors_[p.index_]] = 0.0;
                    prototype_status_[predecessors_[p.index_]] = PROTOTYPE;
                }
            }

        }//end

        for(PriorityQueue::const_iterator q = Q.begin(); q != Q.end(); ++q)
        {
            weight = distance(patterns.pattern[p.index_].get_feature_vector(), patterns.pattern[q->index_].get_feature_vector());

            if(weight < q->cost_)
            {
                Q.update(q->index_,weight);
                predecessors_[q->index_] = p.index_;
            }
        }
    }
    return initial_costs_;
}
