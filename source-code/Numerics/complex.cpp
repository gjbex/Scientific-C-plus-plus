#include <complex>
#include <iostream>
#include <valarray>

using namespace std::complex_literals;

int main() {
    std::complex<double> a {2.0 + 3.0i};
    std::cout << "a.re = " << std::real(a) << ", a.im = " << std::imag(a) << std::endl;
    std::complex<double> b {-3.0 + 2.0i};
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << "sqrt(" << a << ") = " << sqrt(a) << std::endl;
    const std::size_t v_size {5};
    std::valarray<std::complex<double>> v(v_size), w(v_size);
    v[0] = a;
    w[0] = b;
    for (std::size_t i = 1; i < v_size; i++) {
        v[i] = a*v[i - 1];
        w[i] = b*w[i - 1];
    }
    auto z = v - w;
    for (std::size_t i = 0; i < z.size(); i++)
        std::cout << v[i] << " - " << w[i] << " = " << z[i] << std::endl;
    return 0;
}
