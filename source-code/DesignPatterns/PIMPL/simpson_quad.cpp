#include "quad.h"

class Quad::QuadImpl {
    private:
        int n_;
    public:
        QuadImpl() : n_ {1000} {}
        double integrate(Integrand f, const double a, const double b) const {
            double h {(b - a)/n_};
            double sum {0.0};
            for (unsigned j = 1; j <= n_/2; ++j) {
                double x_left {a + (2*j - 2)*h};
                double x_mid {a + (2*j - 1)*h};
                double x_right {a + 2*j*h};
                sum += f(x_left) + 4.0*f(x_mid) + f(x_right);
            }
            return h*sum/3.0;
        }
};

Quad::Quad() : impl {std::make_unique<QuadImpl>()} {}
double Quad::integrate(Integrand f, const double a, const double b) const {
    return impl->integrate(f, a, b);
}
Quad::~Quad() = default;
