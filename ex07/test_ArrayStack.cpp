#include "ArrayStack.h"

int main(void)
{
    // Create an instance of ArrayStack named stack1 using the default constructor
    ArrayStack stack1(5);
    
    // Push several items in this stack
    stack1.push("stack1_A");
    stack1.push("stack1_B");
    stack1.push("stack1_C");
    
    // Test for stack1
    std::cout << stack1.top() << " " << stack1.size() << std::endl;
    
    // Pop all the items
    stack1.pop();
    stack1.pop();
    stack1.pop();
    
    // Try pop from the empty stack, catch exceptions
    try{
        stack1.pop();
    }
    catch(std::out_of_range err){
        std::cout << err.what() << std::endl;
    }
    
    // Try to access the top element of the empty stack, catch exceptions
    try{
        std::cout << stack1.top() << std::endl;
    }
    catch(std::out_of_range err){
        std::cout << err.what() << std::endl;
    }

    return 0;
}
