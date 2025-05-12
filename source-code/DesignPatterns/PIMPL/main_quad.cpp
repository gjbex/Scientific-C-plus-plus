#include <iostream>

#include "quad.h"

double func(double x) {
    return 3.0*x*x - 2.0*x + 5.0;
}

int main(int argc, char *argv[]) {
    Quad quad;
    double a {-1.0};
    double b {1.0};
    double result {quad.integrate(func, a, b)};
    std::cout << "Result: " << result << std::endl;
    return 0;
};
