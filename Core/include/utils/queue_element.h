#ifndef QUEUE_ELEMENT_H
#define QUEUE_ELEMENT_H

namespace opf
{

class QueueElement
{
    friend class PriorityQueue;//allows PriorityQueue to access private data
    private:
    enum Status {BLACK,  /**< status of an element removed from queue. */
                 GREY,  /**< status of an element already inserted and visited. */
                 WHITE  /**< status of an element already inserted but not visited. */
                };

    Status status_;

    public:
    double cost_;
    int index_;

    QueueElement(double cost):cost_(cost){}
    QueueElement(){}

    bool operator<(const QueueElement& other)
    {
        return cost_ < other.cost_;
    }
};
}

#endif // QUEUE_ELEMENT_H
