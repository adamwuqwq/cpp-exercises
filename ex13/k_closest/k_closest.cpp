#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

#define RND_MIN 0
#define RND_MAX 100

std::vector<float> compute_k_closest(std::vector<float> arr, int k)
{
    std::vector<float>::iterator max = std::max_element(arr.begin(), arr.end());
    float max_value = *max;

    std::vector<float> result;
    auto cmp = [&](float first, float second) { return first - max_value > second - max_value; };
    for (int i = 0; i < k; i++)
    {
        std::nth_element(arr.begin(), arr.begin() + i, arr.end(), cmp);
        result.push_back(arr[i]);
    }

    return result;
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

    // Find the k-closest elements to max (k = 5)
    print_nums(compute_k_closest(nums, 5));

    // Use std::sort to check if it is correct
    std::vector<float> nums_sorted = nums;
    std::sort(nums_sorted.begin(), nums_sorted.end());
    print_nums(nums_sorted);

    return 0;
}