#ifndef INTEGRAND_HDR
#define INTEGRAND_HDR

#include <concepts>

template<typename F>
concept Integrand = requires(const F& f, double x) {
    { f(x) } -> std::convertible_to<double>;
};

#endif
