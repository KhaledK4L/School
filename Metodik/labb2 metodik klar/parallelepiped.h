#ifndef LAB2_PARALLELEPIPED_H
#define LAB2_PARALLELEPIPED_H

#include "shape.h"

class parallelepiped : public shape
{
private:
    double width;
    double height;
    double length;

public:
    parallelepiped(const std::string& color, double width, double height, double length);
    double get_area() const override;
};

#endif
