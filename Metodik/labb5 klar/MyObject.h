#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <string>
#include <vector>

class MyObject {
public:
    std::string name;
    double parameter;

    MyObject(const std::string& n, double p);

    // Equality: compare only names
    bool operator==(const MyObject& other) const;
};

// Helper function to create a vector from an array
std::vector<MyObject> createVectorFromArray(const MyObject arr[], int size);

#endif 
