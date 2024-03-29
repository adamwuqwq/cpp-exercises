#include <string>
#include <iostream>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack
{
private:
    int _num_items;      // number of items in the stack
    std::string *_items; // stack items
    int _allocated_size; // size of memory allocated

    void resize(int max_size)
    {
        if (max_size == 0)
            max_size++;

        // Move stack to a new array of size max
        _allocated_size = max_size;
        std::string *temp = new std::string[max_size];
        // Copy
        for (int i = 0; i < _num_items; ++i)
        {
            temp[i] = _items[i];
        }
        delete[] _items;
        _items = temp;
    }

public:
    // Constructors:
    // Default constructor
    ArrayStack()
    {
        // Initialize _num_items to 0, _allocated_size to 0, and set _items to the null pointer,
        _num_items = 0;
        _allocated_size = 0;
        _items = nullptr;
    }

    // Copy constructor
    ArrayStack(const ArrayStack &arr_stack)
    {
        _num_items = arr_stack._num_items;
        _allocated_size = arr_stack._allocated_size;
        _items = new std::string[arr_stack._allocated_size];
        std::copy(arr_stack._items, arr_stack._items + arr_stack._allocated_size, _items);
    }

    // Move constructor
    ArrayStack(ArrayStack &&arr_stack)
    {
        _num_items = arr_stack._num_items;
        _allocated_size = arr_stack._allocated_size;
        _items = arr_stack._items;

        // Reset original object
        arr_stack._items = nullptr;
        arr_stack._num_items = 0;
        arr_stack._allocated_size = 0;
    }

    explicit ArrayStack(int allocated_size)
    {
        // initialize _num_items to 0, pre-allocate memory for an array of size allocated_size and make _items point to it
        _num_items = 0;
        _allocated_size = allocated_size;
        _items = new std::string[allocated_size];
    }

    // Destructor:
    ~ArrayStack()
    {
        delete[] _items;
    }

    // Copy assignment
    ArrayStack &operator=(const ArrayStack &arr_stack)
    {
        if (this == &arr_stack)
            return *this;
        
        delete[] _items;
        _num_items = arr_stack._num_items;
        _allocated_size = arr_stack._allocated_size;
        _items = new std::string[arr_stack._allocated_size];
        std::copy(arr_stack._items, arr_stack._items + arr_stack._allocated_size, _items);
        return *this;
    }

    // Move assignment
    ArrayStack &operator=(ArrayStack &&arr_stack)
    {
        if (this == &arr_stack)
            return *this;
        
        delete[] _items;
        _num_items = arr_stack._num_items;
        _allocated_size = arr_stack._allocated_size;
        _items = arr_stack._items;

        // Reset original object
        arr_stack._items = nullptr;
        arr_stack._num_items = 0;
        arr_stack._allocated_size = 0;

        return *this;
    }

    // Push item to the stack
    void push(const std::string &item)
    {
        if (_num_items == _allocated_size)
            resize(2 * _allocated_size);
        _items[_num_items++] = item;
    }

    // Pop an item
    void pop()
    {
        _num_items--;
        if (_num_items > 0 && _num_items == _allocated_size / 4)
            resize(_allocated_size / 2);
    }

    // Access the top-most item
    std::string top()
    {
        return _items[_num_items - 1];
    }

    // Check if the stack is empty
    bool empty() const { return _num_items == 0; }

    // Return the number of elements in the stack
    int size() const { return _num_items; }
};

#endif // ARRAY_STACK_H