#ifndef MYPRINT_H
#define MYPRINT_H

#include <iostream>
#include "MyObject.h"

class MyPrint {
public:
    void operator()(const MyObject& obj) const {
        std::cout << "Name: " << obj.name
                  << ", Parameter: " << obj.parameter << std::endl;
    }
};

#endif 