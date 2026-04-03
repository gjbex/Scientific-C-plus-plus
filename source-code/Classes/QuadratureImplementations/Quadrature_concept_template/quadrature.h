#ifndef QUADRATURE_HDR
#define QUADRATURE_HDR

#include <concepts>

#include "integrand.h"

template<typename QuadratureMethod, typename Function>
concept Quadrature = Integrand<Function> &&
    requires(const QuadratureMethod& q, const Function& f, double a, double b) {
        { q.integrate(f, a, b) } -> std::convertible_to<double>;
    };

#endif
