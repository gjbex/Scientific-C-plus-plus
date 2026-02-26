#include <chrono>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <memory>

using std::sqrt;

struct Point {
    public:
        double x;
        double y;

        Point();
        static void reset() { x0_ = 0.0; y0_ = 0.0; }

    private:
        static double x0_;
        static double y0_;
};

double Point::x0_ = 0.0;
double Point::y0_ = 0.0;


Point::Point() {
    x = x0_;
    y = y0_;
    x0_ += 0.000001;
    y0_ += 0.000001;
}

using my_time_t = std::chrono::nanoseconds;

int main() {
    const std::size_t i_max {2'000'000'000};
    double dist {0.0};
    Point::reset();
    auto start_time = std::chrono::steady_clock::now();
    Point* point_ptr {(Point*) malloc(sizeof(Point))};
    for (std::size_t i = 0; i < i_max; ++i) {
        Point* p = new(point_ptr) Point();
        dist += sqrt(p->x*p->x + p->y*p->y);
    }
    free(point_ptr);
    auto end_time = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<my_time_t>(end_time - start_time);
    std::cerr << "time: " << duration.count()*1.0e-9 << " s" << std::endl;
    std::cout << "mean distance = " << dist/i_max << std::endl;

    Point::reset();
    dist = 0.0;
    start_time = std::chrono::steady_clock::now();
    for (std::size_t i = 0; i < i_max; ++i) {
        Point* p = new Point();
        dist += sqrt(p->x*p->x + p->y*p->y);
        delete p;
    }
    end_time = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<my_time_t>(end_time - start_time);
    std::cerr << "time: " << duration.count()*1.0e-9 << " s" << std::endl;
    std::cout << "mean distance = " << dist/i_max << std::endl;

    return 0;
}
