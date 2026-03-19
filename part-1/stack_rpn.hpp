#ifndef __stack_rpn__
#define __stack_rpn__

#include "stack.hpp"
#include "stack_enhanced.hpp"
#include <cassert>
#include <functional>

template <typename T>
void plus(Stack<T>& stack)
{
    T a,b; 

    a = stack.top();
    stack.pop();
    b = stack.top();
    stack.pop();
    stack.push(a+b);
}

template <typename T>
void multiplies(Stack<T>& stack)
{
    T a,b;
    a = stack.top();
    stack.pop();
    b = stack.top();
    stack.pop();
    stack.push(a*b);

}

template <typename T>
StackEnhanced<T> &operator<<(StackEnhanced<T>& stack, void (*operation)(Stack<T>&))
{
    operation(stack);
    return stack;
}

#endif // __stack_rpn__