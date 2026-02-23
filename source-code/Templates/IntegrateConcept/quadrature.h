#ifndef QUADRATURE_HDR
#define QUADRATURE_HDR

#include <concepts>

#include "integrand.h"

template <typename T>
concept Quadrature = requires(const T& t, Integrand f, double a, double b) {
    { t.integrate(f, a, b) } -> std::convertible_to<double>;
};

#endif
