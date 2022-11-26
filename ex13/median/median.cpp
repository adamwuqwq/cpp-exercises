#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

#define RND_MIN 0
#define RND_MAX 100

float compute_median(std::vector<float> arr)
{
    auto m = arr.begin() + arr.size() / 2;
    std::nth_element(arr.begin(), m, arr.end());

    if (arr.size() % 2 == 0)
    {
        std::nth_element(arr.begin(), m - 1, arr.end());
        return (arr[arr.size() / 2] + arr[arr.size() / 2 - 1]) / 2;
    }
    else
        return arr[arr.size() / 2];
}

std::vector<float> generate_nums(int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(RND_MIN, RND_MAX);
    std::vector<float> result;

    for (int i = 0; i < size; i++)
        result.push_back((dist(gen) * 100) / 100);

    return result;
}

void print_nums(const std::vector<float> &arr)
{
    for (float i : arr)
        std::cout << i << " ";

    std::cout << "\n";
}

int main(void)
{
    std::vector<float> nums_odd = generate_nums(15);
    std::vector<float> nums_even = generate_nums(18);

    // Print out all the numbers
    std::cout << "Odd(n = 15): ";
    print_nums(nums_odd);
    std::cout << "Even(n = 18): ";
    print_nums(nums_even);

    // Find the medians
    std::cout << "Median of odd(n = 15): " << compute_median(nums_odd) << std::endl;
    std::cout << "Median of even(n = 18): " << compute_median(nums_even) << std::endl;

    // Use std::sort to check if the results are correct
    std::sort(nums_odd.begin(), nums_odd.end());
    std::sort(nums_even.begin(), nums_even.end());
    std::cout << "Odd(n = 15) after sorting: ";
    print_nums(nums_odd);
    std::cout << "Even(n = 18) after sorting: ";
    print_nums(nums_even);

    return 0;
}