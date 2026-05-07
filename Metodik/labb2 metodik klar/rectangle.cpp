#include "rectangle.h"

rectangle::rectangle(const std::string& color, double width, double height)
    : shape(color), width(width), height(height)
{
}

double rectangle::get_area() const
{
    return width * height;
}
