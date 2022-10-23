#include "ArrayStack.h"

// To validate if contents in a and b are identical
bool validator(ArrayStack &a, ArrayStack &b)
{
    while (!a.empty() && !b.empty())
    {
        if (a.top() != b.top())
            return false;

        a.pop(), b.pop();
    }
    return true;
}

int main(void)
{
    // Question 1 --------
    // Create an instance of ArrayStack named stack1 using the default constructor
    ArrayStack stack1;
    // Push several items in this stack
    stack1.push("stack1_A");
    stack1.push("stack1_B");
    stack1.push("stack1_C");
    // Test for stack1
    std::cout << stack1.top() << " " << stack1.size() << std::endl;

    // Create another instance of ArrayStack named stack2 using the other constructor, specify an original size of 5
    ArrayStack stack2(5);
    // Push several items in this stack
    stack2.push("stack2_A");
    stack2.push("stack2_B");
    stack2.push("stack2_C");
    // Test for stack2
    std::cout << stack2.top() << " " << stack2.size() << std::endl;
    // -------- End of Question 1

    // Question 2 --------
    // Copy
    ArrayStack stack3(stack1);
    ArrayStack stack4 = stack2;

    // Assignment
    ArrayStack stack5;
    stack5 = stack1;
    ArrayStack stack6(10);
    stack6 = stack6;

    // Verify that the content of the stacks 'stack1' and 'stack3', 'stack2' and 'stack4' and 'stack1' and 'stack5' are identical.
    std::cout << "stack1, stack3: " << validator(stack1, stack3) << std::endl;
    std::cout << "stack2, stack4: " << validator(stack2, stack4) << std::endl;
    std::cout << "stack1, stack5: " << validator(stack1, stack5) << std::endl;

    // Push several items in 'stack6'.
    stack6.push("stack6_A");
    stack6.push("stack6_B");
    stack6.push("stack6_C");
    // Test for stack6
    std::cout << stack6.top() << " " << stack6.size() << std::endl;
    // -------- End of Question 2

    return 0;
}
