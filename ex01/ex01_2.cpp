#include <iostream>

// Addition only using bitwise operation
unsigned long long add(unsigned long a, unsigned long b)
{
    while (b != 0)
    {
        unsigned long carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

// Multiplication only using bitwise operation
unsigned long long multiply(unsigned long a, unsigned long b)
{
    unsigned long long result = 0;
    while (b > 0)
    {
        if (b & 1)
        {
            result = add(result, a);
        }
        a = a << 1;
        b = b >> 1;
    }
    return result;
}

int main(void)
{
    // Test case #0: should be 6
    std::cout << "2*3:" << multiply(2, 3) << std::endl;

    // Test case #1: should be 92340
    std::cout << "114*810:" << multiply(114, 810) << std::endl;

    // Test case #2: should be 4109358
    std::cout << "1914*2147:" << multiply(1914, 2147) << std::endl;

    return 0;
}
