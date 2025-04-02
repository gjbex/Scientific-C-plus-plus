#include <cmath>
#include <iostream>

#include "static_particle.h"

inline double sqr(double x) {
    return x*x;
}

double StaticParticle::energy() const {
    const double light_speed = 299792.5;
    return mass()*sqr(light_speed);
}

double StaticParticle::dist(const StaticParticle& other) const {
    return sqrt(sqr(x() - other.x()) + sqr(y() - other.y()));
}

std::ostream& operator<<(std::ostream& out, const StaticParticle& p) {
    return out << "(" << p.x() << ", " << p.y() << ")"
           << ", mass = " << p.mass();
}
