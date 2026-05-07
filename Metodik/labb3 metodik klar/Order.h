#ifndef ORDER_HEADER
#define ORDER_HEADER
#include <iostream>
class Order{
public:
    Order(std::string, double);
    std::string getName();
    double getPrice() const;
private:
    std::string name;
    double price;
};
#endif