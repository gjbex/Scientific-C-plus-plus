#include <iostream>
#include <cmath>

using std::sqrt;

double distance(double x, double y);

int main(int argc __attribute__((unused)),
         char *argv[] __attribute__((unused))) {
    double x {0.0};
    double y {0.0};
    while (std::cin >> x >> y) {
        std::cout << distance(x, y) << std::endl;
    }
    return 0;
}

double distance(double x, double y) {
    return sqrt(x*x + y*y);
}
