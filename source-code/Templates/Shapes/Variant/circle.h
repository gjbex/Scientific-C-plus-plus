#ifndef CIRCLE_HDR
#define CIRCLE_HDR

struct Circle {
    private:
        double radius_;
    public:
        explicit Circle(double radius) : radius_(radius) {}
        double area() const { return 3.14159 * radius_*radius_; }
        double perimeter() const { return 2*3.14159 * radius_; }
};

#endif
