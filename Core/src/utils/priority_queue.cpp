#include <utils/priority_queue.h>
#include <limits>
#include <algorithm>
#include <functional>
#include <iterator>


class MaxPolicy
{
public:
    int* index_;
    double* cost_;
    MaxPolicy(int* index, double* cost):index_(index), cost_(cost)
    {
    }

    bool operator()(int index1, int index2)
    {
        return cost_[index1] > cost_[index2];

    }
};

class MinPolicy
{
public:
    int* index_;
    double* cost_;
    MinPolicy(int* index, double* cost):index_(index), cost_(cost)
    {
    }

    bool operator()(int index1, int index2)
    {
        return cost_[index1] < cost_[index2];

    }
};

PriorityQueue::PriorityQueue(int size, Type type): cur_index_(0), size_(size), policy_type(type){
    double default_value;

    indexes_ = new int[size];
    costs_ = new double[size];
    status_ = new Status[size];

    if(type==Type::MIN)
    {
        default_value = numeric_limits<double>::max();
    }
    else
    {
        default_value = 0;
    }

    for(int i=0; i<size; ++i){
        indexes_[i] = i;
    }

    std::fill(costs_, costs_ + size, default_value);
}

PriorityQueue::~PriorityQueue()
{
    delete indexes_;
    delete costs_;
    delete status_;
}

void PriorityQueue::insert(double cost){

    if(full()){
        throw "Queue is full!";
    }
    costs_[cur_index_] = cost;
    status_[cur_index_] = Status::WHITE;
    cur_index_++;

}

int PriorityQueue::remove()
{
    if(empty()){
        throw "Queue is empty!";
    }
    //TODO: mudar essa joca
    cur_index_--;
    status_[cur_index_] = Status::BLACK;
    return indexes_[cur_index_];
}

bool PriorityQueue::min(int index1, int index2)
{
    return costs_[indexes_[index1]] < costs_[indexes_[index2]];
}

bool PriorityQueue::max(int index1, int index2)
{
    return costs_[indexes_[index1]] > costs_[indexes_[index2]];
}

void PriorityQueue::sort()
{
    if(empty()){
        throw "Impossible to sort: queue is empty. Insert elements before do this";
    }
    //TO DO: remover esse if
    if(policy_type == Type::MIN)
    {
        make_heap(indexes_, indexes_+cur_index_, MinPolicy(indexes_, costs_));
        sort_heap(indexes_, indexes_+cur_index_, MinPolicy(indexes_, costs_));
    }
    else
    {
        make_heap(indexes_, indexes_+cur_index_, MaxPolicy(indexes_, costs_));
        sort_heap(indexes_, indexes_+cur_index_, MaxPolicy(indexes_, costs_));
    }
}

void PriorityQueue::update(int index, double cost)
{
    if(status_[index] == Status::BLACK){
        throw "Element %d is already out of queue",index;
    }
    costs_[index] = cost;
    status_[index] = Status::GREY;
}

bool PriorityQueue::empty() const
{
    return cur_index_ <= 0;
}

bool PriorityQueue::full() const
{
    return cur_index_ >= size_;
}

const int* PriorityQueue::begin() const
{
    return indexes_;
}

const int* PriorityQueue::end() const
{
    return indexes_+cur_index_;
}

double PriorityQueue::get_cost(int index) const{
    return costs_[index];
}
