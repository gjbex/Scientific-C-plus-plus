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

        double integrate(const Integrand auto& f,
                         const double a,
                         const double b) const {
            double h {0.5*(b - a)};
            double k {0.5*(a + b)};
            double sum {0.0};
            for (unsigned i = 0; i < _w.size(); ++i) {
                sum += _w[i]*f(h*_x[i] + k);
            }
            return h*sum;
        }
};

#endif
