#include <utils/priority_queue.h>
#include <limits>
#include <algorithm>
#include <functional>
#include <iterator>
#include <exception/opf_exception.h>

using namespace opf;

PriorityQueue::PriorityQueue(int size, HeapPolicy type): size_(size), policy_type_(type), elements(size), indexes_(size){
    initialize();
}

void PriorityQueue::initialize()
{
    double default_value;

    cur_index_ = 0;

    default_value = policy_type_(MAX_QUEUE, MIN_QUEUE);

    for(int i = 0; i < size_; ++i)
    {
        elements[i].index_ = i;
        elements[i].status_ = QueueElement::QueueElement::Status::WHITE;
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
    indexes_[cur_index_] = cur_index_;

    cur_index_++;
}

const QueueElement& PriorityQueue::remove()
{
    if(empty()){
        throw OPFException("Queue is empty!");
    }
    //TODO: mudar essa joca

    pop_heap(elements.begin(), elements.begin()+cur_index_);

    cur_index_--;

    elements[cur_index_].status_ = QueueElement::Status::BLACK;

    return elements[cur_index_];
}

void PriorityQueue::sort()
{
    //Peixinho: isso acaba por causar uma exception no algoritmo, talvez seja melhor simplesmente ordenar nada
    //ao inves de levantar exception, afinal este nao eh um comportamento perigoso
    //o que acha zé?
//    if(empty()){
//        throw OPFException("Impossible to sort an empty queue. Insert elements before to do this");
//    }

    make_heap(elements.begin(), elements.begin() + cur_index_, policy_type_);
    sort_heap(elements.begin(), elements.begin() + cur_index_, policy_type_);

    for (int i = 0; i < cur_index_; ++i) {
        indexes_[elements[i].index_] = i;
    }
}

void PriorityQueue::update(int index, double cost)
{
    int inner_index = indexes_[index];

    if(elements[inner_index].status_ == QueueElement::Status::BLACK){
        throw OPFException("Element " + to_string(index) + " is already out of queue");
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
    return elements.begin();
}

PriorityQueue::const_iterator PriorityQueue::end() const
{
    return elements.begin()+cur_index_;
}

double PriorityQueue::get_cost(int index) const{
    return elements[indexes_[index]].cost_;
}
