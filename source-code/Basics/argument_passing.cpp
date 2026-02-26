#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::sqrt;


std::vector<double> init_vector(std::size_t n);
void update_vector(std::vector<double>& v);

int main(int argc, char *argv[]) {
    std::size_t n {10};
    if (argc > 1)
        n = std::stoi(argv[1]);
    std::vector<double> v = init_vector(n);
    std::cout << "first value " << v[0] << " at " << &v[0] << std::endl;
    std::cout << "last value " << v[n - 1] << " at " << &v[n - 1] << std::endl;
    update_vector(v);
    std::cout << "first value " << v[0] << " at " << &v[0] << std::endl;
    std::cout << "last value " << v[n - 1] << " at " << &v[n - 1] << std::endl;
    std::cout << "size " << &v[n - 1] - &v[0] + 1 << std::endl;
    return 0;
}

std::vector<double> init_vector(std::size_t n) {
    std::vector<double> v(n);
    std::fill(v.begin(), v.end(), 0.0);
    std::cout << "first value " << v[0] << " at " << &v[0] << std::endl;
    std::cout << "last value " << v[n - 1] << " at " << &v[n - 1] << std::endl;
    return v;
}

void update_vector(std::vector<double>& v) {
    std::generate(v.begin(), v.end(),
             [] () { static double x {1.0}; return sqrt(x += 3.0); });
    std::cout << "first value " << v[0] << " at " << &v[0] << std::endl;
    std::cout << "last value " << v[v.size() - 1] << " at "
         << &v[v.size() - 1] << std::endl;
}
