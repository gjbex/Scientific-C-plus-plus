#ifndef SQUARE_HDR
#define SQUARE_HDR

struct Square {
    private:
        double side_;
    public:
        explicit Square(double side) : side_(side) {}
        double area() const { return side_*side_; }
        double perimeter() const { return 4.0*side_; }
};

#endif
