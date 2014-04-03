/*
 * priotiryqueue.h
 *
 *
 */

#ifndef PRIOTIRY_QUEUE_H_
#define PRIOTIRY_QUEUE_H_
#include <vector>
#include <iterator>
#include <functional>

using namespace std;

/**Class for handling minimum and maximum priority queues.
 * The methods of this class are particularly implemented to deal with queues that OPF-based algorithms need to.
 * Usage exemple:
 * See other usages of this class in {@link mst_prototype, @link opf_training}
 * \authors Alan Zanoni Peixinho apeixinho@studends.ic.unicamp.br
 *\authors Luis Augusto Martins Pereria lmartins@ic.unicamb.br
 * \version 1.0.0
*/

class PriorityQueue{
public:

    typedef vector<int>::iterator iterator;
    typedef vector<int>::const_iterator const_iterator;

    struct QueueElement
    {
        enum Status {BLACK,  /**< status of an element removed from queue. */
                     GREY,  /**< status of an element already inserted and visited. */
                     WHITE  /**< status of an element already inserted but not visited. */
                    };
        double cost_;
        int index_;
        Status status_;

        bool operator<(const QueueElement& other)
        {
            return cost_ < other.cost_;
        }
    };

    /** An enumeration for setting removal policy of queue.
    */
    enum Type {MIN, /**< enum value MIN for minimum priority queue. */
               MAX /**< enum value MAX for maximum priority queue. */
              };

    /**Creates an empty instance with defined size and removal policy.
     * A queue with minimal priority is created if the policy is not denifed.
     *@param size size of queue.
     *@param type removal policy
     *@see Type
    */
    PriorityQueue(int size, Type type = Type::MIN);

    /**Creates an instance using an initial vector of costs and a defined removal policy.
     * A queue with minimal priority is created if the policy is not denifed.
     * Costs are only inserted in queue
     *@param begin
     * @param end
     *@param type removal policy
     *@see Type
    */
    template <typename Iterator> PriorityQueue(Iterator begin, Iterator end, Type polyce_type = Type::MIN){
        size_ = end - begin;
        policy_type_ = polyce_type;

        initialize();

        int idx = 0;
        for(auto it = begin; it!=end; ++it)
        {
            elements[idx].cost_ = *it;
        }
    }


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

    /**Removes an element from queue following the removal policy (minimum or maximum).
     * If the queue is empy, then an exception rises.
     * @return insertion index of an element removed from queue.
    */
    int remove();

    /**Updates the cost of an element if it still in the priority queue.
     * If the element is out of the queue, then an exception rises.
     * The {\@link sort} method should be called after a cost(s) to be updated.
     * @param index index of element whose cost has to be updated.
     * @param cost cost value to be update in the queue.
    */
    void update(int index, double cost);

    /**Checks if the queue is empty.
     * @return true if the queue is empty, and false otherwise.
    */
    bool empty() const;

    /**Checks if the queue is full.
     * @return true if the queue is full, and false otherwise.
    */
    bool full() const;

    /**Sorts the queue according to removal policy (minimum or maximum).
     * If the queue is empty, then an exception rises.
     * Call this method after a insertion or update of cost(s).
     */
    void sort();

    /**Returns the memory address of the first element in the queue.
     * @see end
    */
    const_iterator begin() const;

    /**Returns the memory address of the last element in the queue.
     * * @see begin
    */
    const_iterator end() const;

    /**Returns the cost of a particular element in the queue.
    *If the element is out of queue, then an exception rises.
    * @param index index of the element in the queue which one wants to know the cost.
    */
    double get_cost(int index)const;

private:

    Type policy_type_;

    /**
     * @brief initialize initialize data structures
     */
    void initialize();

    int size_;
    int cur_index_;
    vector<int> indexes_;
    vector<QueueElement> elements;
};

#endif /* PRIOTIRY_QUEUE_H */
