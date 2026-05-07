#ifndef MYBINOP_H
#define MYBINOP_H

#include "MyObject.h"

class MyBinOp {
public:
    double operator()(double sum, const MyObject& obj) const {
        return sum + obj.parameter;
    }
};

#endif 