/*
 * priotiryqueue.h
 *
 *  Created on: Mar 19, 2014
 *      Author: luis
 */

#ifndef OPF_HEAP_H_
#define OPF_HEAP_H


class Pair
{
public:
	Pair();
    Pair(int x, double y):index(x),cost(y)
    {}
    int index;
    double cost;

    bool operator <(Pair& other_pair)
    {
        return cost < other_pair.cost;
    }
};

class OPFHeap{
public:
	OPFHeap(int size);
	void Push(Pair pair);
	Pair Pop();
	void Update(int index, double cost);
	bool IsEmpty();
private:
	enum Status {BLACK, GREY, WHITE};
	Pair *begin_;
	Pair *end_;
	Pair *heap_;
	int size_;
	Status *status_;
};



#endif /* OPF_HEAP_H */
