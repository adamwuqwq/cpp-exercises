#include "ArrayStack.h"

int main(void)
{
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

    return 0;
}
