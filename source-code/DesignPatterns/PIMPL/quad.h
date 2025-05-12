#ifndef QUAD_HDR
#define QUAD_HDR

#include <functional>
#include <memory>

using Integrand = std::function<double(double)>;


class Quad {
    private:
        class QuadImpl;
        std::unique_ptr<QuadImpl> impl;
    public:
        Quad();
        double integrate(Integrand f, const double a, const double b) const;
        ~Quad();

};

#endif
