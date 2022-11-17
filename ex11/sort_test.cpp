#include "sort.h"
#include <vector>

// Show all the values in vector<int>
void show_values(std::vector<int> arr)
{
    for (auto i : arr)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    // Declare an vector<int> for test
    std::vector<int> arr = {114, 810, 798, 1999, 3, -1, 6592};

    // Before sort
    std::cout << "before: ";
    show_values(arr);

    // After sort
    std::cout << "after: ";
    PL4::sort(arr.begin(), arr.end());
    show_values(arr);

    return 0;
}