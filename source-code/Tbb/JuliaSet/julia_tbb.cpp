#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
#include <iostream>
#include <tbb/tbb.h>
#include <valarray>

using std::sqrt;

using my_time_t = std::chrono::nanoseconds;

using Complex_t = std::complex<double>;
using Coords_t = std::valarray<double>;
using Z_t = std::valarray<Complex_t>;
using Img_t = std::valarray<std::size_t>;

Coords_t coordinates(double min_coord, double max_coord, std::size_t steps);
Z_t z_values(const Coords_t& x_coords, const Coords_t& y_coords);
Img_t iterate_zs(Z_t& zs, const Complex_t& c, std::size_t max_iters);
void print_results(const Img_t& ns);

int main(int argc, char *argv[]) {
    const Complex_t c(-0.62772, - 0.42193);
    const double x1 {-1.8};
    const double x2 {1.8};
    const double y1 {-1.8};
    const double y2 {1.8};
    const std::size_t max_iters {255};
    std::size_t steps {100};
    if (argc > 1)
        steps = std::stoi(argv[1]);
    Coords_t x_coords = coordinates(x1, x2, steps);
    Coords_t y_coords = coordinates(y1, y2, steps);
    Z_t zs = z_values(x_coords, y_coords);
    auto start_time = std::chrono::steady_clock::now();
    Img_t ns = iterate_zs(zs, c, max_iters);
    auto end_time = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<my_time_t>(end_time - start_time);
    std::cerr << "time: " << duration.count()*1.0e-9 << " s" << std::endl;
    print_results(ns);
    return 0;
}

Coords_t coordinates(double min_coord, double max_coord, std::size_t steps) {
    Coords_t coords(steps);
    const double step {(max_coord - min_coord)/steps};
    double value {min_coord};
    for (std::size_t i = 0; i < steps; i++) {
        coords[i] = value;
        value += step;
    }
    return coords;
}

Z_t z_values(const Coords_t& x_coords, const Coords_t& y_coords) {
    Z_t zs(x_coords.size()*y_coords.size());
    tbb::parallel_for(tbb::blocked_range<std::size_t>(0, y_coords.size()),
            [&] (const tbb::blocked_range<std::size_t> r) {
                for (std::size_t i = r.begin(); i < r.end(); i++)
                    for (std::size_t j = 0; j < x_coords.size(); j++) {
                        Complex_t z(x_coords[j], y_coords[i]);
                        zs[i*x_coords.size() + j] = z;
                    }
            });
    return zs;
}

int iterate_z(Complex_t z, const Complex_t& c, std::size_t max_iters) {
    std::size_t n {0};
    const Complex_t z_in {z};
    while (std::real(z)*std::real(z) + std::imag(z)*std::imag(z) < 4.0 && n++ < max_iters)
        z = z*z + c;
    return n;
}

Img_t iterate_zs(Z_t& zs, const Complex_t& c, std::size_t max_iters) {
    Img_t ns(0ul, zs.size());
    tbb::parallel_for(tbb::blocked_range<std::size_t>(0, zs.size()),
            [&] (const tbb::blocked_range<std::size_t> r) {
                for (std::size_t i = r.begin(); i < r.end(); i++)
                    ns[i] = iterate_z(zs[i], c, max_iters);
            });
    return ns;
}

void print_results(const Img_t& ns) {
    std::size_t steps = ((std::size_t) sqrt(ns.size()) + 0.1);
    std::size_t count {0};
    for (auto n: ns) {
        std::cout << n;
        if (++count % steps == 0)
            std::cout << std::endl;
        else
            std::cout << " ";
    }
}
