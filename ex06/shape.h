#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class Shape
{
protected:
    std::string _name;

public:
    // Default (null) constructor
    Shape(){};

    // The (virtual) destructor
    virtual ~Shape(){};

    // Copy constructor
    Shape(const Shape &src){};

    // Return the string corresponding to the name of the primitive (e.g. circle, rectangle, ...)
    virtual std::string get_name() const = 0;

    // Return the area of the shape
    virtual float compute_area() const = 0;

    // Create a new object (using the default constructor)
    virtual Shape *create() const = 0;

    // Return a copy of the object (using the copy constructor)
    virtual Shape *clone() const = 0;
};

#endif