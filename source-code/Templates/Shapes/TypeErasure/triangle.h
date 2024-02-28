#ifndef TRIANGLE_HDR
#define TRIANGLE_HDR

struct Triangle {
    private:
        double base_;
        double height_;
    public:
        explicit Triangle(double base, double height) : base_(base), height_(height) {}
        double area() const { return 0.5*base_*height_; }
        double perimeter() const { return 3*base_; }
};

#endif
