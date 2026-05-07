#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "rounded_rectangle.h"

rounded_rectangle::rounded_rectangle(const std::string& color, double width, double height, double radius)
    : rectangle(color, width, height), radius(radius)
{
}

double rounded_rectangle::get_area() const
{
    double full = rectangle::get_area();  // width * height

    // Cut-outs: 4 kvadrater minus 1 cirkel
    double removed = 4 * radius * radius - M_PI * radius * radius;

    return full - removed;
}
