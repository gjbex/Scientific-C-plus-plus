#ifndef QUAD_HDR
#define QUAD_HDR

#include <functional>

using Integrand = std::function<double(double)>;

template<class Derived>
struct Quad {
    public:
        double integrate(Integrand f, const double a, const double b) const {
            return static_cast<const Derived*>(this)->integrate_impl(f, a, b);
        }
};

#endif
