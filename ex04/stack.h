#ifndef STACK_H
#define STACK_H

// Insert the relevant headers here

// Class for representing two dimensional points
struct Point
{
    int x;
    int y;
};

// Class for representing a stack
class Stack
{
public:
    Stack(const int max_size = 100) : _max_size(max_size),
                                _top(-1), _data(new Point[max_size]) {}

    // Destructor: deallocation _data
    ~Stack() { delete[] _data; }

    // Interface

    // Check whether the stack is empty
    bool empty() const;

    // Check whether the stack is full
    bool full() const;

    // Return the number of elements in the stack
    int size() const;

    // Insert element on top
    // print an error message on std::cerr when overflow
    void push(const Point);

    // Remove element on top
    // print an error message on std::cerr when underflow
    void pop();

    // Acces the topmost element
    Point top() const;

private:
    const int _max_size; // capacity of the fixed-size stack
    int _top;            // index to the top of the stack
    Point *_data;        // data container
};
#endif