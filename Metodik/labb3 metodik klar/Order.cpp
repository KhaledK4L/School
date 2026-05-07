#include "Order.h"
Order::Order(std::string _name, double _price): name(_name), price(_price){}
std::string Order::getName(){
    return name;
}
double Order::getPrice() const{
    return price;
}