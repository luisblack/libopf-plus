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

    void insert(double cost);
    int remove();
    void update(int index, double cost);
    bool empty() const;
    bool full() const;

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
