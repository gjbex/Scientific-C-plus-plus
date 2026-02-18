#include <iostream>

struct Particle {
    double x, y;
    int charge;
};


int main() {
    // Using aggregate initialization
    Particle p1 {1.0, 2.0, -1};

    // Using designated initializers (C++20)
    Particle p2 {.x = 3.0, .y = 4.0, .charge = 1};

    // This would not compile because designated initializers are not in order
    // Particle p3 {.charge = 1, .x = 5.0, .y = 6.0};

    std::cout << "Particle 1: x=" << p1.x << ", y=" << p1.y << ", charge=" << p1.charge << std::endl;
    std::cout << "Particle 2: x=" << p2.x << ", y=" << p2.y << ", charge=" << p2.charge << std::endl;

    return 0;
}
