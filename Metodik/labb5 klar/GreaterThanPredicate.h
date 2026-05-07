#ifndef GREATERTHANPREDICATE_H
#define GREATERTHANPREDICATE_H

#include "MyObject.h"

class GreaterThanPredicate {
private:
    double threshold;

public:
    GreaterThanPredicate(double t) : threshold(t) {}

    bool operator()(const MyObject& obj) const {
        return obj.parameter > threshold;
    }
};

#endif 