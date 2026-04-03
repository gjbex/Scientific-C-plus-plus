#ifndef QUADRATURE_HDR
#define QUADRATURE_HDR

#include <concepts>

#include "integrand.h"

template<typename T, typename F>
concept Quadrature = Integrand<F> &&
    requires(const T& t, const F& f, double a, double b) {
        { t.integrate(f, a, b) } -> std::convertible_to<double>;
    };

#endif
