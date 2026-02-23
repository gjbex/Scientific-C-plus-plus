#ifndef GAUSSIAN_QUAD_HDR
#define GAUSSIAN_QUAD_HDR

#include "integrand.h"
#include <vector>

class GaussianQuad {
    private:
        std::vector<double> _x;
        std::vector<double> _w;
    public:
        GaussianQuad();
        double integrate(Integrand f, const double a, const double b) const;
};

#endif
