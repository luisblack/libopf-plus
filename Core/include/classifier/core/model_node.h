#ifndef MODEL_NODE_H_
#define MODEL_NODE_H_

#include <input/pattern.h>

/**\authors Alan Zanoni Peixinho apeixinho@studends.ic.unicamp.br
*\authors Luis Augusto Martins Pereria lmartins@ic.unicamb.br
* \version 1.0.0
*/
class ModelNode : public Pattern{
public:

    ModelNode();

    /**Returns the propagated cost of a node.
    */
    double get_cost() const;

    /**Sets the propagated cost to a node.
     * @param cost cost propagated through a path.
     */
    void set_cost(double cost);

    /**Returns the index of predecessor node.
    */
    int get_predecessor()const;

    /**Sets a predecessor to a node.
     * @param predecessor index of a predecessor node.
    */
    void set_predecessor(int predecessor);

private:
    double cost_;
    int predecessor_;
};

#endif // MODEL_NODE_H
