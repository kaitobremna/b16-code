#ifndef __binary_saerch_tree_enhanced__
#define __binary_saerch_tree_enhanced__

#include "binary_search_tree.hpp"

// Finds the node with the minimum value in the BST
template <typename T> T bst_min(const T &tree)
{
    // If the tree is completely empty, there is no minimum
    if (tree == nullptr) return nullptr;

    T current = tree;
    
    // Keep walking down the left branches until there are no more left children
    while (left(current) != nullptr) {
        current = left(current);
    }
    
    // We have reached the bottom-leftmost node!
    return current;
}

// Finds the node with the maximum value in the BST
template <typename T> T bst_max(const T &tree)
{
    // If the tree is completely empty, there is no maximum
    if (tree == nullptr) return nullptr;

    T current = tree;
    
    // Keep walking down the right branches until there are no more right children
    while (right(current) != nullptr) {
        current = right(current);
    }
    
    // We have reached the bottom-rightmost node!
    return current;
}


#endif // __binary_saerch_tree_enhanced__