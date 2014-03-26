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

PriorityQueue::PriorityQueue(int size, Type type): cur_idx_(0), size_(size), policy_type(type){
    double default_value;

    index_ = new int[size];
    cost_ = new double[size];
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
        index_[i] = i;
    }

    std::fill(cost_, cost_ + size, default_value);
}

PriorityQueue::~PriorityQueue()
{
    delete index_;
    delete cost_;
    delete status_;
}

void PriorityQueue::insert(double cost){
    if(!full()){
        cost_[cur_idx_] = cost;
        status_[cur_idx_] = Status::WHITE;
        cur_idx_++;
    }
}

int PriorityQueue::remove()
{
    if(!empty())
    {
        cur_idx_--;
        status_[cur_idx_] = Status::BLACK;
        return index_[cur_idx_];
    }
    //TODO: mudar essa joca
    return -1;
}

bool PriorityQueue::min(int index1, int index2)
{
    return cost_[index_[index1]] < cost_[index_[index2]];
}

bool PriorityQueue::max(int index1, int index2)
{
    return cost_[index_[index1]] > cost_[index_[index2]];
}

void PriorityQueue::sort()
{
    //TO DO: remover esse if
    if(policy_type == Type::MIN)
    {
        make_heap(index_, index_+cur_idx_, MinPolicy(index_, cost_));
        sort_heap(index_, index_+cur_idx_, MinPolicy(index_, cost_));
    }
    else
    {
        make_heap(index_, index_+cur_idx_, MaxPolicy(index_, cost_));
        sort_heap(index_, index_+cur_idx_, MaxPolicy(index_, cost_));
    }
}

void PriorityQueue::update(int index, double cost)
{
    cost_[index] = cost;
    status_[index] = Status::GREY;
}

bool PriorityQueue::empty() const
{
    return cur_idx_ <= 0;
}

bool PriorityQueue::full() const
{
    return cur_idx_ >= size_;
}

const int* PriorityQueue::begin() const
{
    return index_;
}

const int* PriorityQueue::end() const
{
    return index_+cur_idx_;
}

double PriorityQueue::get_cost(int index) const{
    return cost_[index];
}
