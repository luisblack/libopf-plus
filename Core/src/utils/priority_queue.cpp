#include <utils/priority_queue.h>
#include <limits>
#include <algorithm>
#include <functional>
#include <iterator>


bool max_policy(PriorityQueue::QueueElement& e1, PriorityQueue::QueueElement& e2)
{
    return e1.cost_ > e2.cost_;
}

bool min_policy(PriorityQueue::QueueElement& e1, PriorityQueue::QueueElement& e2)
{
    return e1.cost_ < e2.cost_;
}

PriorityQueue::PriorityQueue(int size, Type type): size_(size), policy_type_(type), elements(size), indexes_(size){
    initialize();
}

void PriorityQueue::initialize()
{
    double default_value;

    cur_index_ = 0;

    if(policy_type_==Type::MIN)
    {
        default_value = numeric_limits<double>::max();
    }
    else
    {
        default_value = 0;
    }

    for(int i = 0; i < size_; ++i)
    {
        elements[i].index_ = i;
        elements[i].status_ = QueueElement::Status::WHITE;
    }
}

PriorityQueue::~PriorityQueue()
{
}

void PriorityQueue::insert(double cost){

    if(full()){
        throw "Queue is full!";
    }

    elements[cur_index_].cost_ = cost;
    elements[cur_index_].status_ = QueueElement::Status::WHITE;

    cur_index_++;
}

int PriorityQueue::remove()
{
    if(empty()){
        throw "Queue is empty!";
    }
    //TODO: mudar essa joca

    pop_heap(elements.begin(), elements.begin()+cur_index_);

    vector<QueueElement> elementzors(elements.begin(), elements.end());
    cur_index_--;

    elements[cur_index_].status_ = QueueElement::Status::BLACK;

    return elements[cur_index_].index_;
}

void PriorityQueue::sort()
{
    if(empty()){
        throw "Impossible to sort an empty queue. Insert elements before to do this";
    }
    //TO DO: remover esse if
    if(policy_type_ == Type::MIN)
    {
        make_heap(elements.begin(), elements.end(), min_policy);
        sort_heap(elements.begin(), elements.end(), min_policy);
    }
    else
    {
        make_heap(elements.begin(), elements.end(), max_policy);
        sort_heap(elements.begin(), elements.end(), max_policy);
    }

    for (int i = 0; i < cur_index_; ++i) {
        indexes_[elements[i].index_] = i;
    }
}

void PriorityQueue::update(int index, double cost)
{
    int inner_index = indexes_[index];

    if(elements[inner_index].status_ == QueueElement::Status::BLACK){
        throw "Element " + to_string(index) + " is already out of queue";
    }
    elements[inner_index].cost_ = cost;
    elements[inner_index].status_ = QueueElement::Status::GREY;
}

bool PriorityQueue::empty() const
{
    return cur_index_ <= 0;
}

bool PriorityQueue::full() const
{
    return cur_index_ >= size_;
}

PriorityQueue::const_iterator PriorityQueue::begin() const
{
    return indexes_.begin();
}

PriorityQueue::const_iterator PriorityQueue::end() const
{
    return indexes_.end();
}

double PriorityQueue::get_cost(int index) const{
    return elements[indexes_[index]].cost_;
}
