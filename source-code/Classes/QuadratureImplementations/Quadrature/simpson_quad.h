#ifndef SIMPSON_QUAD_HDR
#define SIMPSON_QUAD_HDR

#include "quad.h"

class SimpsonQuad : public Quad {
    private:
        unsigned n_;
    public:
        SimpsonQuad(unsigned n) : Quad(), n_ {n} {};
        double integrate(Integrand f, const double a, const double b) const
            override;
        unsigned n() const {return n_; };
};

#endif
