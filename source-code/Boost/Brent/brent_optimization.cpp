#include <boost/math/tools/minima.hpp>
#include <iostream>

double f(double x)
{
   return (x + 3) * (x - 1) * (x - 1); // (x + 3)(x - 1)^2;
}

int main() {
    using boost::math::tools::brent_find_minima;
    const int digits = std::numeric_limits<double>::digits;
    std::pair<double, double> r = brent_find_minima(f, -4.0, 2.0, digits);
    std::cout.precision(std::numeric_limits<double>::digits10);
    std::cout << "Minimum found at x = " << r.first << ", f(x) = " << r.second << std::endl;
    return 0;
}
