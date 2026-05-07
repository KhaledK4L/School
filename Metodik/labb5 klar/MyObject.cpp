#include "MyObject.h"

MyObject::MyObject(const std::string& n, double p)
    : name(n), parameter(p) {}

bool MyObject::operator==(const MyObject& other) const {
    return name == other.name;
}

std::vector<MyObject> createVectorFromArray(const MyObject arr[], int size) {
    return std::vector<MyObject>(arr, arr + size);
}