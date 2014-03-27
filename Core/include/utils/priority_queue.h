/*
 * priotiryqueue.h
 *
 *  Created on: Mar 19, 2014
 *      Author: luis
 */

#ifndef OPF_HEAP_H_
#define OPF_HEAP_H
#include <vector>

#include <functional>

using namespace std;



class PriorityQueue{
public:

    enum Type {MIN, MAX};

    PriorityQueue(int size, Type type = Type::MIN);
    ~PriorityQueue();

    /**Inserts cost in priority qeue.
     * @param cost cost value to be inserted in priority qeue;
    */
    void insert(double cost);

    /**Removes an element of priority queue following the removal policy (min or max).
    */
    int remove();

    /**Updates the cost of an element if it still in the priority queue.
     * If the element is out of the queue, then an exception rises. The sort function must to call after a cost(s) is update.
     * @param index index of element whose cost has to be updated.
     * @param cost cost value to be update in the qeue.
    */
    void update(int index, double cost);

    /**Checks if the queue is empty*/
    bool empty() const;

    /**Checks if the queue is full*/
    bool full() const;

    /**Sorts the queue according to removal policy (min or max).*/
    void sort();

    const int* begin() const;
    const int* end() const;

    double get_cost(int index)const;

private:

    Type policy_type;

    bool min(int, int);
    bool max(int, int);

	enum Status {BLACK, GREY, WHITE};
    int size_;
    int cur_idx_;
    Status* status_;
    int* index_;
    double* cost_;
};



#endif /* OPF_HEAP_H */
