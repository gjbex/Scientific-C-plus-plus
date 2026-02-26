#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
#include <iostream>
#include <valarray>

using my_time_t = std::chrono::nanoseconds;

using cmplx = std::complex<double>;

std::valarray<double> coordinates(double min_coord, double max_coord,
                             std::size_t steps);
std::valarray<cmplx> z_values(const std::valarray<double>& x_coords,
                         const std::valarray<double>& y_coords);
std::valarray<int> iterate_zs(std::valarray<cmplx>& zs, const std::complex<double>& c,
                         std::size_t max_iters);
void print_results(const std::valarray<int>& ns);

int main(int argc, char *argv[]) {
    const cmplx c(-0.62772, - 0.42193);
    const double x1 {-1.8};
    const double x2 {1.8};
    const double y1 {-1.8};
    const double y2 {1.8};
    const std::size_t max_iters {255};
    std::size_t steps {100};
    if (argc > 1)
        steps = std::stoi(argv[1]);
    std::valarray<double> x_coords = coordinates(x1, x2, steps);
    std::valarray<double> y_coords = coordinates(y1, y2, steps);
    std::valarray<cmplx> zs = z_values(x_coords, y_coords);
    auto start_time = std::chrono::steady_clock::now();
    std::valarray<int> ns = iterate_zs(zs, c, max_iters);
    auto end_time = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<my_time_t>(end_time - start_time);
    std::cerr << "time: " << duration.count()*1.0e-9 << " s" << std::endl;
    print_results(ns);
    return 0;
}

std::valarray<double> coordinates(double min_coord, double max_coord,
                             std::size_t steps) {
    std::valarray<double> coords(steps);
    const double step {(max_coord - min_coord)/steps};
    double value {min_coord};
    for (std::size_t i = 0; i < steps; i++) {
        coords[i] = value;
        value += step;
    }
    return coords;
}

std::valarray<cmplx> z_values(const std::valarray<double>& x_coords,
                         const std::valarray<double>& y_coords) {
    std::valarray<cmplx> zs(x_coords.size()*y_coords.size());
    std::size_t i {0};
    for (auto y: y_coords)
        for (auto x: x_coords) {
            std::complex<double> z(x, y);
            zs[i++] = z;
        }
    return zs;
}

int iterate_z(cmplx z, const cmplx& c, std::size_t max_iters) {
    std::size_t n {0};
    const std::complex<double> z_in {z};
    while (std::abs(z) < 2.0 && n++ < max_iters)
        z = z*z + c;
    return n;
}

std::valarray<int> iterate_zs(std::valarray<cmplx>& zs, const std::complex<double>& c,
                         std::size_t max_iters) {
    std::valarray<int> ns(zs.size());
    std::size_t i {0};
    for (auto z: zs)
        ns[i++] = iterate_z(z, c, max_iters);
    return ns;
}

void print_results(const std::valarray<int>& ns) {
    std::size_t steps = ((std::size_t) std::sqrt(ns.size()) + 0.1);
    std::size_t count {0};
    for (auto n: ns) {
        std::cout << n;
        if (++count % steps == 0)
            std::cout << std::endl;
        else
            std::cout << " ";
    }
}
