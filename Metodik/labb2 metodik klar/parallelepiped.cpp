#include "parallelepiped.h"

parallelepiped::parallelepiped(const std::string& color, double width, double height, double length)
    : shape(color), width(width), height(height), length(length)
{
}

double parallelepiped::get_area() const
{
    return 2 * (width * height + width * length + height * length);
}
