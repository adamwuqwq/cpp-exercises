#include "point.h"
#include "shape.h"
#include "rectangle.h"
#include "disk.h"

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
    Disk disk_3(Point(), 4.0f);

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

    return 0;
}