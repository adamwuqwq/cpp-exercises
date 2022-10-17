#include <iostream>
#include "stack.h"

int main(void)
{
    // Create a stack which size = 3
    Stack a(3);

    // Test for the following 3 points
    Point p1, p2, p3;
    p1.x = 1, p1.y = 2;
    p2.x = 3, p2.y = 5;
    p3.x = 6, p3.y = 4;

    // Test of empty() function: should be empty -> 1
    std::cout << "is_empty: " << a.empty() << std::endl;

    // Test of push() function: push p1, p2, p3
    std::cout << "pushed p1(1, 2), p2(3, 5), p3(6, 4) into the stack" << std::endl;
    a.push(p1);
    a.push(p2);
    a.push(p3);

    // Test of size() function: should be 3
    std::cout << "size: " << a.size() << std::endl;

    // Test of full() function: should be full -> 1
    std::cout << "is_full: " << a.full() << std::endl;

    // Test of pop() function: pop out p3, p2
    std::cout << "popped out p2(3, 5), p3(6, 4) from the stack" << std::endl;
    a.pop();
    a.pop();

    // Test of top() function: should be Point p1 -> (1, 2)
    std::cout << "top: (" << a.top().x << ", " << a.top().y << ")" << std::endl;

    // Test of empty() function: should not be empty -> 0
    std::cout << "is_empty: " << a.empty() << std::endl;

    // Test of pop() function: pop out p1, then pop out 1 more time -> underflow
    std::cout << "popped out p1(1, 2) from the stack" << std::endl;
    a.pop();
    std::cout << "popped out an element from empty stack" << std::endl;
    a.pop();

    return 0;
}