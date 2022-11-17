#ifndef POINT_H
#define POINT_H
#include <cmath>

struct Point
{
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double x, y, z;
};

class Compare
{
private:
    const double distance(const Point &pt)
    {
        return sqrt(pt.x * pt.x + pt.y * pt.y + pt.z * pt.z);
    }

public:
    bool operator()(const Point &first, const Point &second)
    {
        return distance(first) > distance(second);
    }
};

#endif