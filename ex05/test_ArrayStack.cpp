#include "ArrayStack.h"

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
    std::cout << "stack1: " << stack1.top() << " " << stack1.size() << "; stack3: " << stack3.top() << " " << stack3.size() << std::endl;
    std::cout << "stack2: " << stack2.top() << " " << stack2.size() << "; stack4: " << stack4.top() << " " << stack4.size() << std::endl;
    std::cout << "stack1: " << stack1.top() << " " << stack1.size() << "; stack5: " << stack5.top() << " " << stack5.size() << std::endl;

    // Push several items in 'stack6'.
    stack6.push("stack6_A");
    stack6.push("stack6_B");
    stack6.push("stack6_C");
    // Test for stack6
    std::cout << stack6.top() << " " << stack6.size() << std::endl;
    // -------- End of Question 2

    // Question 3 --------
    // Move
    ArrayStack stack7 = std::move(stack5);
    stack6 = std::move(stack2);

    // Write tests to check your implementation of the move semantic. 
    std::cout << "stack7: " << stack7.top() << " " << stack7.size() << std::endl;
    std::cout << "stack5: " << stack5.size() << std::endl;
    std::cout << "stack6: " << stack6.top() << " " << stack6.size() << std::endl;
    std::cout << "stack2: " << stack2.size() << std::endl;
    // -------- End of Question 3

    return 0;
}
