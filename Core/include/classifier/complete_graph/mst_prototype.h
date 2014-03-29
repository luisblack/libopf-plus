#ifndef MST_PROTOTYPES_H
#define MST_PROTOTYPES_H

#include <classifier/core/prototype_strategy.h>
#include <utils/distance.h>

/**Class to handle prototypes selection by using a Minimum Spanning Tree (MST). Prim's algorithm is performed to generate the MST.
 * Two patterns on MST are selected as prototypes if they are connected and belong to different classes.
 * \authors Alan Zanoni Peixinho apeixinho@studends.ic.unicamp.br
 *\authors Luis Augusto Martins Pereria lmartins@ic.unicamb.br
 * \version 1.0.0
*/
class MSTPrototypes : public PrototypesStrategy
{
public:
    MSTPrototypes();
    /**Returns a array of size of patterns with zero value is a pattern is a prototype and infinity otherwise.
     * @param distance a distance function.
     * @param patterns a set of single pattern.
     * */
    virtual vector<double> SelectPrototypes(opf::Distance distance, Patterns patterns);
private:
    const int NIL = -1;
    const bool PROTOTYPE = true;
};

#endif // MST_PROTOTYPES_H
