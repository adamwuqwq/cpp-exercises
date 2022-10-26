#ifndef POINT_H
#define POINT_H

class Point
{
private:
    float _x_coordinate, _y_coordinate;

public:
    // Default (null) constructor
    Point() : _x_coordinate(0.0f), _y_coordinate(0.0f) {};

    // Constructor that accept coordinate
    Point(float x, float y) : _x_coordinate(x), _y_coordinate(y) {};

    // Return x coordinate
    float getX() const
    {
        return _x_coordinate;
    }

    // Return y coordinate
    float getY() const
    {
        return _y_coordinate;
    }

    // Set position (coordinate) of current Point
    void set_position(const float x, const float y)
    {
        _x_coordinate = x;
        _y_coordinate = y;
    }
};

#endif