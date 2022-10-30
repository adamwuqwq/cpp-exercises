#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include "point.h"

class Polygon : public Shape
{
private:
    Point* _point_list;
    int _number_points;

public:
    // Default (null) constructor
    Polygon();

    // Constructor
    Polygon(int number_points, Point *point_list);
    
    // Destructor
    ~Polygon();

    // Copy constructor
    Polygon(const Polygon &src);

    // Return the string corresponding to the name of the primitive (Polygon)
    std::string get_name() const;

    // Return the area of the shape
    float compute_area() const;

    // Create a new object (using the default constructor)
    Polygon *create() const;

    // Return a copy of the object (using the copy constructor)
    Polygon *clone() const;
};

#endif