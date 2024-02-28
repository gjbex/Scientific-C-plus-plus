#ifndef CIRCLE_HDR
#define CIRCLE_HDR

#include "shape.h"

struct Circle : public Shape<Circle> {
    private:
        double radius_;
    public:
        explicit Circle(double radius) : radius_(radius) {}
        double area_impl() const { return 3.14159 * radius_*radius_; }
        double perimeter_impl() const { return 2*3.14159 * radius_; }
};

#endif
