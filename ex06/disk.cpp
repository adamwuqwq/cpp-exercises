#include "disk.h"
#define PI 3.14159265359

// Default (null) constructor
Disk::Disk() : _radius(0.0f)
{
    _name = "disk";
}

// Constructor
Disk::Disk(Point corner, float radius) : _radius(radius)
{
    _name = "disk";
    _center.set_position(corner.getX(), corner.getY());
}

// Copy constructor
Disk::Disk(const Disk &src)
{
    _name = src._name;
    _center = src._center;
    _radius = src._radius;
}

// Return the string corresponding to the name of the primitive (Disk)
std::string Disk::get_name() const
{
    return _name;
}

// Return the area of the shape
float Disk::compute_area() const
{
    return PI * _radius * _radius;
}

// Create a new object (using the default constructor)
Disk *Disk::create() const
{
    return new Disk;
}

// Return a copy of the object (using the copy constructor)
Disk *Disk::clone() const
{
    return new Disk(*this);
}