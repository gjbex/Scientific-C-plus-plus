#ifndef CIRCLE_HDR
#define CIRCLE_HDR

#include <numbers>
#include "shape.h"

using std::numbers::pi;

struct Circle : public Shape<Circle> {
    private:
        double radius_;
    public:
        explicit Circle(double radius) : radius_(radius) {}
        double area_impl() const { return pi*radius_*radius_; }
        double perimeter_impl() const { return 2.0*pi*radius_; }
};

#endif
