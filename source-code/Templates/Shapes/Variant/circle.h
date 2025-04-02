#ifndef CIRCLE_HDR
#define CIRCLE_HDR

#include <numbers>

using std::numbers::pi;

struct Circle {
    private:
        double radius_;
    public:
        explicit Circle(double radius) : radius_(radius) {}
        double area() const { return pi*radius_*radius_; }
        double perimeter() const { return 2.0*pi*radius_; }
};

#endif
