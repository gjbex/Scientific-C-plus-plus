#include <iostream>
#include "particle.h"

int main(void) {
    StaticParticle p_s(0.0, 0.0, 1.0);
    std::cout << "static particle: " << p_s << std::endl;
    Particle p1(1.0, 0.0, 1.0, 0.5, 1.0);
    std::cout << "particle 1: " << p1 << std::endl;
    Particle p2(0.0, 1.0, 0.0, 0.5, 2.0);
    std::cout << "particle 2: " << p2 << std::endl;
    std::cout << p1 << std::endl;
    const double delta_t = 0.1;
    p1.move(delta_t);
    std::cout << "particle 1 moved during " << delta_t << ": " << p1 <<  std::endl;
    std::cout << "distance particle 1, static partice: "
         << p1.dist(p_s) << std::endl;
    std::cout << "distance particle 1, partice 2: "
         << p1.dist(p2) << std::endl;
    return 0;
}
