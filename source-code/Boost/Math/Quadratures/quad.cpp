#include <boost/math/quadrature/gauss.hpp>
#include <cmath>
#include <functional>
#include <iostream>

int main(int argc, char* argv[]) {
    using namespace boost::math::quadrature;
    if (argc != 2) {
        std::cerr << "expecting beta maximum\n";
        std::exit(1);
    }
    const double beta_max {std::stod(argv[1])};
    const double a {0.0};
    const double b {2.0};
    for (double beta = 0.0; beta <= beta_max; beta += 0.1) {
        double value {gauss<double, 7>::integrate(
                  [beta] (double x) { return 0.5*(tanh(beta*x) + 1.0); },  
                  a, b)};
        std::cout << beta << " " << value << "\n";
    }
    return 0;
}
