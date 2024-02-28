#ifndef SQUARE_HDR
#define SQUARE_HDR

#include "shape.h"

struct Square : public Shape {
    private:
        double side_;
    public:
        explicit Square(double side) : side_(side) {}
        double area() const override { return side_*side_; }
        double perimeter() const override { return 4.0*side_; }
};

#endif
