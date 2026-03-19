#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        assert(this->_size>0);
        return this->_storage[this->_tail()];
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        assert(this->_size>0);
        return this->_storage[this->_tail()];
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        assert(this->_size<this->_storage.size());

        if (this->_position == 0) {
            this->_position = this->_storage.size() - 1;
        } else {
            this->_position--;
        }

        this->_storage[this->_position] = value;
        this->_size++;
    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        assert(this->_size > 0); // Assert not empty
        // Simply reduce the size by 1. The tail index naturally shrinks!
        this->_size--;
    }

    // Remove all elements from the queue
    void clear() { 
        // Just reset the size to 0. We don't even need to touch the elements.
        this->_size = 0;
        this->_position = 0;
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        assert(this->_size > 0);
        return (this->_size-1 + this->_position) % this->_storage.size();
    }
};

#endif // __queue_enhanced__