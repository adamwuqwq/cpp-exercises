#include <iostream>
#include "stack.h"

// Check whether the stack is empty
bool Stack::empty()
{
    if (_top == -1)
        return true;
    else
        return false;
}

// Check whether the stack is full
bool Stack::full()
{
    if (_top == _max_size)
        return true;
    else
        return false;
}

// Return the number of elements in the stack
int Stack::size()
{
    return _top + 1;
}

// Insert element on top
// print an error message on std::cerr when overflow
void Stack::push(Point a)
{
    if (_top + 1 > _max_size)
        std::cerr << "Stack overflow!" << std::endl;
    else
        _data[++_top] = a;
}

// Remove element on top
// print an error message on std::cerr when underflow
void Stack::pop()
{
    if (_top == -1)
        std::cerr << "Stack underflow!" << std::endl;
    else
        _top--;
}

// Acces the topmost element
Point Stack::top()
{
    if (empty())
        std::cerr << "Empty stack!" << std::endl;
    else
        return _data[_top];
}
