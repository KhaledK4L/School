#ifndef LAB2_SQUARE_H
#define LAB2_SQUARE_H

#include "shape.h"

class square : public shape
{
private:
    double side;

public:
    square(const std::string& color, double side);
    double get_area() const override;
};

#endif
