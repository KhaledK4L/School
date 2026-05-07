#ifndef LAB2_SHAPE_H
#define LAB2_SHAPE_H

#include <string>

class shape
{
protected:
    std::string color;

public:
    explicit shape(const std::string& color);
    virtual ~shape() = default;

    std::string get_color() const;
    virtual double get_area() const = 0;
};

#endif
