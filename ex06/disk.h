#ifndef DISK_H
#define DISK_H
#include "shape.h"
#include "point.h"

class Disk : public Shape
{
private:
    Point _center;
    float _radius;

public:
    // Default (null) constructor
    Disk();

    // Constructor
    Disk(Point center, float radius);
    
    // Destructor
    ~Disk(){};

    // Copy constructor
    Disk(const Disk &src);

    // Return the string corresponding to the name of the primitive (rectangle)
    std::string get_name() const;

    // Return the area of the shape
    float compute_area() const;

    // Create a new object (using the default constructor)
    Disk *create() const;

    // Return a copy of the object (using the copy constructor)
    Disk *clone() const;
};

#endif