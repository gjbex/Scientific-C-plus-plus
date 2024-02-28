#ifndef SQUARE_HDR
#define SQUARE_HDR

#include "shape.h"

struct Square : public Shape<Square> {
    private:
        double side_;
    public:
        explicit Square(double side) : side_(side) {}
        double area_impl() const { return side_*side_; }
        double perimeter_impl() const { return 4.0*side_; }
};

#endif
