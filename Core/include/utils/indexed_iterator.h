#ifndef INDEXED_ITERATOR_H
#define INDEXED_ITERATOR_H

#include <vector>

namespace opf
{
    template<class T> class IndexedIterator
    {
    public:
        std::vector<T> &v_;
        std::vector<int> &index_;
        int cur_idx_;

    public:
        IndexedIterator(std::vector<T> &v, std::vector<int> &index):
            v_(v), index_(index),cur_idx_(0){
        }

        static IndexedIterator begin(std::vector<T> &v, std::vector<int> &index)
        {
            IndexedIterator it = IndexedIterator(v, index);
            return it;
        }

        static IndexedIterator end(std::vector<T> &v, std::vector<int> &index)
        {
            IndexedIterator it = IndexedIterator(v, index);
            it.cur_idx_ = index.size();
            return it;
        }


        bool operator!=(const IndexedIterator &other)
        {
            return other.cur_idx_ != cur_idx_;
        }

        void operator++()
        {
            cur_idx_++;
        }

        void operator--()
        {
            cur_idx_--;
        }

        const T& operator*()
        {
            return v_[index_[cur_idx_]];
        }

        const T& operator ->()
        {
            return v_[index_[cur_idx_]];
        }
    };
}

#endif // INDEXED_ITERATOR_H
