#ifndef CIRCLE_HDR
#define CIRCLE_HDR

#include "shape.h"

struct Circle : public Shape {
    private:
        double radius_;
    public:
        explicit Circle(double radius) : radius_(radius) {}
        double area() const override { return 3.14159 * radius_*radius_; }
        double perimeter() const override { return 2*3.14159 * radius_; }
};

#endif
