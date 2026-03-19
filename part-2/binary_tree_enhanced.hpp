#ifndef __binary_tree_enhanced__
#define __binary_tree_enhanced__

#include <cassert>
#include <vector>
#include <memory>

// A class representing a binary tree
template <typename V> struct BinaryTreeEnhanced {
    V _value;
    std::unique_ptr<BinaryTreeEnhanced<V>> _left;
    std::unique_ptr<BinaryTreeEnhanced<V>> _right;

    // WRITE YOUR CODE HERE
    BinaryTreeEnhanced<V>* _parent = nullptr;

    friend V &value(BinaryTreeEnhanced *t) { return t->_value; }
    friend const V &value(const BinaryTreeEnhanced *t)
    {
        return t->_value;
    }
    friend BinaryTreeEnhanced *left(const BinaryTreeEnhanced *t)
    {
        return t->_left.get();
    }
    friend BinaryTreeEnhanced *right(const BinaryTreeEnhanced *t)
    {
        return t->_right.get();
    }
    friend BinaryTreeEnhanced *parent(const BinaryTreeEnhanced *t)
    {
        //WRITE YOUR CODE HERE
        return t->_parent;
    }
};

// A helper function to build an enhanced binary tree
template <typename V>
std::unique_ptr<BinaryTreeEnhanced<V>>
make_binary_tree_enhanced(const V &value,
                          std::unique_ptr<BinaryTreeEnhanced<V>> l,
                          std::unique_ptr<BinaryTreeEnhanced<V>> r)
{
    //WRITE YOUR CODE HERE
    //Create parent node
    auto node = std::unique_ptr<BinaryTreeEnhanced<V>>{
        new BinaryTreeEnhanced<V>{value, std::move(l), std::move(r), nullptr}}; //AGGREGATE INITIALISATION - in C++11+, 
                                                                                //no need for constructor if not initialised,
                        
    // Tell the left child that this new node is its parent                                                                            //will assign by order of appearance           
    if (node->_left != nullptr) {
        node->_left->_parent = node.get();
    }
    
    // Tell the right child that this new node is its parent
    if (node->_right != nullptr) {
        node->_right->_parent = node.get();
    }

    // Now it is safe to return the fully wired-up tree
    return node;
}                                                                                                                                    


#endif // __binary_tree_enhanced__