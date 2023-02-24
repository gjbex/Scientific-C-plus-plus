#ifndef POINT_HDR
#define POINT_HDR

class Point {
    private:
        int x_, y_;
    public:
        Point(int x, int y) : x_ {x}, y_ {y} {}
        int x() const { return x_; }
        int y() const { return y_; }
};

#endif
