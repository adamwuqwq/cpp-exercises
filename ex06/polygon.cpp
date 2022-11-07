#include "polygon.h"

// Default (null) constructor
Polygon::Polygon() : _point_list(nullptr), _number_points(0)
{
    _name = "polygon";
}

// Constructor
Polygon::Polygon(int number_points, Point* point_list) : _number_points(number_points), _point_list(point_list)
{
    _name = "polygon";
}

// Destructor
Polygon::~Polygon()
{
    delete[] _point_list;
}

// Copy constructor
Polygon::Polygon(const Polygon &src)
{
    _name = src._name;
    _number_points = src._number_points;
    _point_list = new Point[src._number_points + 1];
    std::copy(src._point_list, src._point_list + src._number_points, _point_list);
}

// Return the string corresponding to the name of the primitive (Polygon)
std::string Polygon::get_name() const
{
    return _name;
}

// Return the area of the shape
float Polygon::compute_area() const
{
    float sum = 0.0f;
    for (int i = 0; i < _number_points; i++) 
        sum += (_point_list[i].get_x() * _point_list[i+1].get_y() - _point_list[i].get_y() * _point_list[i+1].get_x());
    
    return sum / 2;
}

// Create a new object (using the default constructor)
Polygon* Polygon::create() const
{
    return new Polygon;   
}

// Return a copy of the object (using the copy constructor)
Polygon* Polygon::clone() const
{
    return new Polygon(*this);
}