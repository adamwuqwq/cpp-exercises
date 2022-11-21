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
    std::vector<float> nums = generate_nums(15);

    // Print out all the numbers
    print_nums(nums);

    // Find the median
    std::cout << compute_median(nums) << std::endl;

    // Use std::sort to check if it is correct
    std::vector<float> nums_sorted = nums;
    std::sort(nums_sorted.begin(), nums_sorted.end());
    print_nums(nums_sorted);

    return 0;
}