#include "circle.h"
#include <numbers>

circle::circle(const std::string& color, double radius)
    : shape(color), radius(radius)
{
}

double circle::get_area() const
{
    return std::numbers::pi * radius * radius;
}