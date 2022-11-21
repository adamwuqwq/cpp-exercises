#include <iostream>
#include <queue>
#include <vector>
#include <random>
#include "Point.h"

#define RND_MIN 0
#define RND_MAX 100

std::vector<Point> find_k_closest(int k, std::vector<Point> pt_list)
{
    auto cmp = [](Point first, Point second) { return first.distance() > second.distance(); };
    std::priority_queue<Point, std::vector<Point>, decltype(cmp)> pt_queue(pt_list.begin(), pt_list.end(), cmp);
    std::vector<Point> k_closest;

    for (int i = 0; i < k; i++)
    {
        k_closest.push_back(pt_queue.top());
        pt_queue.pop();
    }

    return k_closest;
}

std::vector<Point> generate_points(int n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(RND_MIN, RND_MAX);
    std::vector<Point> pt_list;

    for (int i = 0; i < n; i++)
    {
        Point pt(floor(dist(gen) * 100) / 100, floor(dist(gen) * 100) / 100, floor(dist(gen) * 100) / 100);
        pt_list.push_back(pt);
    }

    return pt_list;
}

int main(void)
{
    std::vector<Point> pts = generate_points(20);

    std::cout << "Points: " << std::endl;
    for (Point i : pts)
        std::cout << "(" << i.x << ", " << i.y << ", " << i.z << "): " << sqrt(i.x * i.x + i.y * i.y + i.z * i.z) << std::endl;

    std::cout << "K - closest (K = 10): " << std::endl;
    std::vector<Point> kc = find_k_closest(10, pts);
    for (Point i : kc)
        std::cout << "(" << i.x << ", " << i.y << ", " << i.z << "): " << sqrt(i.x * i.x + i.y * i.y + i.z * i.z) << std::endl;

    return 0;
}