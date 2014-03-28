/*
 * priotiryqueue.h
 *
 *\author Alan Zanoni Peixinho
 *\author Luis Augusto Martins Pereria
 *
 *
 */

#ifndef OPF_HEAP_H_
#define OPF_HEAP_H
#include <vector>

#include <functional>

using namespace std;

/**A class for handling minimum and maximum priority queues.
 * Usage example:
 * #include<priority_queue>.
 * PriorityQueue Q(3,Type::MIN);.
 * Q.insert(0.1);.
 * Q.insert(0.01);.
 * Q.insert(10.0);.
 * Q.sort();.
*/

class PriorityQueue{
public:

    /** An enumeration for setting removal policy of queue.
    */
    enum Type {MIN, /**< enum value MIN for minimum priority queue. */
               MAX /**< enum value MAX for maximum priority queue. */
              };

    /**Constructor creating a empty priority queue with defined size and removal policy. A queue with minimal priority is created if the policy is not denifed.
     *@param size defined size of queue.
     *@param type removal policy
     *@see Type
    */
    PriorityQueue(int size, Type type = Type::MIN);

    /**Constructor using a vector with costs and a defined removal policy.
     * A queue with minimal priority is created if the policy is not denifed.
     * Costs are only inserted in queue
     *@param costs vector with costs.
     *@param type removal policy
     *@see Type
    */
    PriorityQueue(vector<double>costs, Type type = Type::MIN);

    /**Destructor of priority queue.
    */
    ~PriorityQueue();

    /**Inserts cost in priority queue.
     * If the queue is full, then an exception rises.
     * The sort method should be called after a cost(s) to be inserted.
     * @param cost cost value to be inserted in the qeue;
     * @exception
    */
    void insert(double cost);

    /**Returns an index element of priority queue following the removal policy (minimum or maximum).
     * @return an index of element removed from queue.
    */
    int remove();

    /**Updates the cost of an element if it still in the priority queue.
     * If the element is out of the queue, then an exception rises.
     * The sort method should be called after a cost(s) to be updated.
     * @param index index of element whose cost has to be updated.
     * @param cost cost value to be update in the queue.
    */
    void update(int index, double cost);

    /**Returns true if the queue is empty, and false otherwise.*/
    bool empty() const;

    /**Returns true if the queue is full, and false otherwise.*/
    bool full() const;

    /**Sorts the queue according to removal policy (minimum or maximum).
     * If the queue is empty, then an exception rises.
     * Call this method after a insertion or update of cost(s).
     */
    void sort();

    /**Returns the memory address of the first element in the queue.
     * @see end
    */
    const int* begin() const;

    /**Returns the memory address of the last element in the queue.
     * * @see begin
    */
    const int* end() const;

    /**Returns the cost of a particular element in the queue.
    *If the element is out of queue, then an exception rises.
    * @param index index of the element in the queue which one wants to know the cost.
    */
    double get_cost(int index)const;

private:

    Type policy_type;

    bool min(int, int);
    bool max(int, int);

	enum Status {BLACK, GREY, WHITE};
    int size_;
    int cur_index_;
    Status* status_;
    int* indexes_;
    double* costs_;
};

#endif /* OPF_HEAP_H */
