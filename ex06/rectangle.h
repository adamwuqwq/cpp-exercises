#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
#include "point.h"

class Rectangle : public Shape
{
private:
    Point _left_corner;
    float _width, _height;

public:
    // Default (null) constructor
    Rectangle();

    // Constructor
    Rectangle(Point left_corner, float width, float height);
    
    // Destructor
    ~Rectangle(){};

    // Copy constructor
    Rectangle(const Rectangle &src);

    // Return the string corresponding to the name of the primitive (rectangle)
    std::string get_name() const;

    // Return the area of the shape
    float compute_area() const;

    // Create a new object (using the default constructor)
    Rectangle *create() const;

    // Return a copy of the object (using the copy constructor)
    Rectangle *clone() const;
};

#endif