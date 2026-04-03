#ifndef QUAD_HDR
#define QUAD_HDR

#include <functional>

using Integrand = std::function<double(double)>;

struct Quad {
    public:
        double integrate(this auto& self, Integrand f, const double a, const double b) {
            return self.integrate_impl(f, a, b);
        }
};

#endif
