#ifndef SHAPE_HDR
#define SHAPE_HDR

struct Shape {
    public:
        virtual double area() const = 0;
        virtual double perimeter() const = 0;
        virtual ~Shape() = default;
};

#endif
