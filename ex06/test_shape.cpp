#include <cmath>
#include "point.h"
#include "shape.h"
#include "rectangle.h"
#include "disk.h"
#include "polygon.h"
#define PI 3.14159265359f

int main(void)
{
    // Test for Rectangle class:
    // Create some Rectangle objects
    Rectangle rect_1;
    Rectangle rect_2(Point(1.0f, 1.0f), 3.0f, 2.0f);
    Rectangle rect_3(Point(), 5.0f, 6.0f);

    // Test get_name, all of them should be "rectangle"
    std::cout << "Name of rect_1: " << rect_1.get_name() << std::endl;
    std::cout << "Name of rect_2: " << rect_2.get_name() << std::endl;
    std::cout << "Name of rect_3: " << rect_3.get_name() << std::endl;

    // Test compute_area, should be: 0, 6, 30
    std::cout << "Area of rect_1: " << rect_1.compute_area() << std::endl;
    std::cout << "Area of rect_2: " << rect_2.compute_area() << std::endl;
    std::cout << "Area of rect_3: " << rect_3.compute_area() << std::endl;

    // Test create, all of them should be "rectangle, 0"
    Rectangle *rect_4 = rect_1.create();
    Rectangle *rect_5 = rect_2.create();
    std::cout << "rect_4: " << rect_4->get_name() << ", " << rect_4->compute_area() << std::endl;
    std::cout << "rect_5: " << rect_5->get_name() << ", " << rect_5->compute_area() << std::endl;

    // Test clone, should be: "rectangle, 0", "rectangle, 6", "rectangle, 30"
    Rectangle *rect_6 = rect_1.clone();
    Rectangle *rect_7 = rect_2.clone();
    Rectangle *rect_8 = rect_3.clone();
    std::cout << "rect_6: " << rect_6->get_name() << ", " << rect_6->compute_area() << std::endl;
    std::cout << "rect_7: " << rect_7->get_name() << ", " << rect_7->compute_area() << std::endl;
    std::cout << "rect_8: " << rect_8->get_name() << ", " << rect_8->compute_area() << std::endl;

    // Test for Disk class:
    // Create some Disk objects
    Disk disk_1;
    Disk disk_2(Point(1.0f, 1.0f), 3.0f);
    Disk disk_3(Point(0.0f, 0.0f), 4.0f);

    // Test get_name, all of them should be "disk"
    std::cout << "Name of disk_1: " << disk_1.get_name() << std::endl;
    std::cout << "Name of disk_2: " << disk_2.get_name() << std::endl;
    std::cout << "Name of disk_3: " << disk_3.get_name() << std::endl;

    // Test compute_area, should be: 0, 28.27, 50.27
    std::cout << "Area of disk_1: " << disk_1.compute_area() << std::endl;
    std::cout << "Area of disk_2: " << disk_2.compute_area() << std::endl;
    std::cout << "Area of disk_3: " << disk_3.compute_area() << std::endl;

    // Test create, all of them should be "disk, 0"
    Disk *disk_4 = disk_1.create();
    Disk *disk_5 = disk_2.create();
    std::cout << "disk_4: " << disk_4->get_name() << ", " << disk_4->compute_area() << std::endl;
    std::cout << "disk_5: " << disk_5->get_name() << ", " << disk_5->compute_area() << std::endl;

    // Test clone, should be: "disk, 0", "disk, 28.27", "disk, 50.27"
    Disk *disk_6 = disk_1.clone();
    Disk *disk_7 = disk_2.clone();
    Disk *disk_8 = disk_3.clone();
    std::cout << "disk_6: " << disk_6->get_name() << ", " << disk_6->compute_area() << std::endl;
    std::cout << "disk_7: " << disk_7->get_name() << ", " << disk_7->compute_area() << std::endl;
    std::cout << "disk_8: " << disk_8->get_name() << ", " << disk_8->compute_area() << std::endl;

    // Test for Polygon class:
    // Test for a 4-vertice polygon(rectangle), area should be equivalent to rect_2: "polygon, 6"
    Point *pnt_1 = new Point[4];
    pnt_1[0] = Point(1.0f, 1.0f), pnt_1[1] = Point(4.0f, 1.0f), pnt_1[2] = Point(4.0f, 3.0f), pnt_1[3] = Point(1.0f, 1.0f);
    Polygon poly_1(4, pnt_1);
    std::cout << "poly_1: " << poly_1.get_name() << ", " << poly_1.compute_area() << std::endl;

    // Test for a 64-vertice(equally distributed on a circle) polygon, area should be close to disk_3
    const float radius = 4.0f;
    const int vertice_num = 64;
    const float angle = 2 * PI / vertice_num;
    Point *pnt_2 = new Point[vertice_num];
    // Generate the vertices
    for (int i = 0; i < vertice_num; i++)
    {
        float x = radius * cos(-PI + angle * i);
        float y = radius * sin(-PI + angle * i);
        pnt_2[i] = Point(x, y);     
    }
    // Test output, should be "polygon, a number close to 50.27"
    Polygon poly_2(vertice_num, pnt_2);
    std::cout << "poly_2: " << poly_2.get_name() << ", " << poly_2.compute_area() << std::endl;

    return 0;
}