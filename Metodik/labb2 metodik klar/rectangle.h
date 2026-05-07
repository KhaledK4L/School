#ifndef LAB2_RECTANGLE_H
#define LAB2_RECTANGLE_H

#include "shape.h"

class rectangle : public shape
{
private:
    double width;
    double height;

public:
    rectangle(const std::string& color, double width, double height);

    double get_area() const override;
};

#endif
