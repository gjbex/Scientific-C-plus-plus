#ifndef GAUSSIAN_QUAD_HDR
#define GAUSSIAN_QUAD_HDR

#include <vector>
#include "quad.h"

class GaussianQuad : public Quad<GaussianQuad> {
    private:
        std::vector<double> x_;
        std::vector<double> w_;
    public:
        GaussianQuad();
        double integrate_impl(Integrand f, const double a, const double b) const;
};

#endif
