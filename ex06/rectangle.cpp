#include "rectangle.h"

// Default (null) constructor
Rectangle::Rectangle() : _width(0.0f), _height(0.0f)
{
    _name = "rectangle";
}

// Constructor
Rectangle::Rectangle(Point left_corner, float width, float height) : _width(width), _height(height)
{
    _name = "rectangle";
    _left_corner.set_position(left_corner.getX(), left_corner.getY());
}

// Copy constructor
Rectangle::Rectangle(const Rectangle &src)
{
    _name = src._name;
    _left_corner = src._left_corner;
    _width = src._width;
    _height = src._height;
}

// Return the string corresponding to the name of the primitive (rectangle)
std::string Rectangle::get_name() const
{
    return _name;
}

// Return the area of the shape
float Rectangle::compute_area() const
{
    return _width * _height;
}

// Create a new object (using the default constructor)
Rectangle* Rectangle::create() const
{
    return new Rectangle;
}

// Return a copy of the object (using the copy constructor)
Rectangle* Rectangle::clone() const
{
    return new Rectangle(*this);
}