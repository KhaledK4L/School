#ifndef MYUNOP_H
#define MYUNOP_H

class MyUnOp {
private:
    double mean;

public:
    MyUnOp(double m) : mean(m) {}

    double operator()(double x) const {
        return x - mean;
    }
};

#endif 