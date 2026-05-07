#include "shape.h"

shape::shape(const std::string& color)
    : color(color)
{
}

std::string shape::get_color() const
{
    return color;
}
