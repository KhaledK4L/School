#include <iostream>
#include <vector>
#include <memory>

#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "cylinder.h"
#include "parallelepiped.h"
#include "rounded_rectangle.h"

using shape_ptr = std::unique_ptr<shape>;

void get_data(const std::vector<shape_ptr>& shapes);

int main()
{
    std::vector<shape_ptr> shapes;

    shapes.push_back(std::make_unique<circle>("Red", 2));
    shapes.push_back(std::make_unique<rectangle>("Blue", 3, 4));
    shapes.push_back(std::make_unique<square>("Green", 5));
    shapes.push_back(std::make_unique<cylinder>("Yellow", 3, 6));
    shapes.push_back(std::make_unique<parallelepiped>("Orange", 2, 3, 4));
    shapes.push_back(std::make_unique<rounded_rectangle>("Purple", 10, 15, 2));

    get_data(shapes);
    return 0;
}

void get_data(const std::vector<shape_ptr>& shapes)
{
    double total = 0;

    for (const auto& s : shapes)
    {
        std::cout << "Color: " << s->get_color()
                  << "\tArea: " << s->get_area() << "\n";

        total += s->get_area();
    }

    std::cout << "\nTOTAL AREA: " << total << "\n";
}
