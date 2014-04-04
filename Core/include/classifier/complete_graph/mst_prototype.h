#ifndef MST_PROTOTYPES_H
#define MST_PROTOTYPES_H

#include <classifier/core/prototypes_strategy.h>
#include <utils/distance.h>

namespace opf{

/**Class for handling prototypes selection by using a Minimum Spanning Tree (MST). Prim's algorithm is performed to generate the MST.
 * \authors Alan Zanoni Peixinho apeixinho@studends.ic.unicamp.br
 *\authors Luis Augusto Martins Pereria lmartins@ic.unicamb.br
 * \version 1.0.0
*/
class MSTPrototypes : public PrototypesStrategy
{
public:
    MSTPrototypes();
    /**Generates a MST to perform a prototype selection.
     * Two patterns on MST are selected as prototypes if they are connected and belong to different classes.
     * @param distance a distance function.
     * @param patterns a set of single pattern.
     * @returns vector a vector of size of patterns with zero value is a pattern is a prototype and infinity otherwise.
     * */
    virtual vector<double> SelectPrototypes(Distance distance, Patterns patterns);
private:
    const static int NIL = -1;
    const static bool PROTOTYPE = true;
    vector<double>initial_costs_;
    vector<int>predecessors_;
    vector<bool>prototype_status_;
};

}
#endif // MST_PROTOTYPES_H

