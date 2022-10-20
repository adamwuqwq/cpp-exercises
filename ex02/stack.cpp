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
    if (_top + 1 == _max_size)
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
    if (full())
        std::cerr << "Stack overflow!" << std::endl;
    else
        _data[++_top] = a;
}

// Remove element on top
// print an error message on std::cerr when underflow
void Stack::pop()
{
    if (empty())
        std::cerr << "Stack underflow!" << std::endl;
    else
        _top--;
}

// Access the topmost element
Point Stack::top()
{
    if (empty())
        throw std::out_of_range("Empty stack!");

    return _data[_top];
}
