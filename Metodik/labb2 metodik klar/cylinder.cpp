#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "cylinder.h"

cylinder::cylinder(const std::string& color, double radius, double height)
    : shape(color), radius(radius), height(height)
{
}

double cylinder::get_area() const
{
    double base = M_PI * radius * radius;
    double side = 2 * M_PI * radius * height;
    return 2 * base + side;
}
