
#ifndef __list_enhanced__
#define __list_enhanced__

#include "list.hpp"
#include <iostream>

template <typename T> void list_delete_after(Node<T> *node)
{
    // WRITE YOUR CODE HERE
    if (node != nullptr && node->next != nullptr) {
        
        // Take ownership of the node we want to delete
        std::unique_ptr<Node<T>> to_delete = std::move(node->next);
        
        // Rescue the rest of the list by moving it into the current node's 'next'
        node->next = std::move(to_delete->next);
    }
}

#endif // __list_enhanced__