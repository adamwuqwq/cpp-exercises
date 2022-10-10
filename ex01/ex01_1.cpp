#include <iostream>

bool parity(unsigned long x)
{
    bool parity = 0;
    while (x)
    {
        parity = !parity;
        x = x & (x - 1);
    }
    return parity;
}

int main(void)
{
    // Test case #0: should be even(1)
    std::cout << "1:" << parity(1) << std::endl;

    // Test case #1: should be odd(0)
    std::cout << "114:" << parity(114) << std::endl;

    // Test case #2: should be even(1)
    std::cout << "817:" << parity(817) << std::endl;

    return 0;
}
