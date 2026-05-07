#ifndef LAB2_CYLINDER_H
#define LAB2_CYLINDER_H

#include "shape.h"

class cylinder : public shape
{
private:
    double radius;
    double height;

public:
    cylinder(const std::string& color, double radius, double height);
    double get_area() const override;
};

#endif
