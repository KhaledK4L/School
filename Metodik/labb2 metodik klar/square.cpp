#include "square.h"

square::square(const std::string& color, double side)
    : shape(color), side(side)
{
}

double square::get_area() const
{
    return side * side;
}
