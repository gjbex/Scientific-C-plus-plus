#include <cmath>
#include <iostream>
#include <limits>


int main() {
    std::cout << std::numeric_limits<short>::min() << " < int < "
         << std::numeric_limits<short>::max() << std::endl;
    std::cout << std::numeric_limits<int>::min() << " < int < "
         << std::numeric_limits<int>::max() << std::endl;
    std::cout << std::numeric_limits<long>::min() << " < long < "
         << std::numeric_limits<long>::max() << std::endl;
    std::cout << "float < " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "0.0f < " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "1.0f < 1.0f + " << std::numeric_limits<float>::epsilon() << std::endl;
    std::cout << "float digits: " << std::numeric_limits<float>::digits10 << std::endl;
    std::cout << "double < " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "0.0 < " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "1.0 < 1.0 + " << std::numeric_limits<double>::epsilon() << std::endl;
    std::cout << "double digits: " << std::numeric_limits<double>::digits10 << std::endl;
    std::cout << "long double < " << std::numeric_limits<long double>::max() << std::endl;
    std::cout << "0.0 < " << std::numeric_limits<long double>::min() << std::endl;
    std::cout << "1.0 < 1.0 + " << std::numeric_limits<long double>::epsilon()
         << std::endl;
    std::cout << "long double digits: " << std::numeric_limits<long double>::digits10 << std::endl;
    double x {1000.0};
    if (!std::isfinite(exp(x)))
        std::cout << "exp(" << x << ") is infinity: " << exp(x)
                  << std::endl;
    x = -1.0;
    if (!std::isfinite(sqrt(x)))
        std::cout << "sqrt(" << x << ") is NaN: " << sqrt(x) << std::endl;
    return 0;
}
