#ifndef LAB2_CIRCLE_H
#define LAB2_CIRCLE_H

#include "shape.h"

class circle : public shape
{
private:
    double radius;

public:
    circle(const std::string& color, double radius);
    double get_area() const override;
};

#endif
