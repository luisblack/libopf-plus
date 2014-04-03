#ifndef OPF_CLASSIFYING_H
#define OPF_CLASSIFYING_H

#include <classifier/core/classifying_strategy.h>
#include <vector>

/**Class to handle prototypes selection by using a Minimum Spanning Tree (MST). Prim's algorithm is performed to generate the MST.
 * Two patterns on MST are selected as prototypes if they are connected and belong to different classes.
 *
 * \authors Alan Zanoni Peixinho apeixinho@studends.ic.unicamp.br
 *\authors Luis Augusto Martins Pereria lmartins@ic.unicamb.br
 * \version 1.0.0
 * */
class OPFClassifying : public ClassifyingStrategy{
   OPFClassifying();
   virtual vector<double> classify(Model model, Patterns test);
};

#endif // OPF_CLASSIFYING_H
