#include <cmath>
#include <iostream>
#include <tuple>

using Particle = std::tuple<double, double, double, double>;

double distance(const Particle& lhs, const Particle& rhs) {
    const auto dx = std::get<0>(lhs) - std::get<0>(rhs);
    const auto dy = std::get<1>(lhs) - std::get<1>(rhs);
    const auto dz = std::get<2>(lhs) - std::get<2>(rhs);
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

void print_particle(const Particle& particle) {
    std::cout << "("
              << std::get<0>(particle) << ", "
              << std::get<1>(particle) << ", "
              << std::get<2>(particle) << "), mass = "
              << std::get<3>(particle);
}

int main() {
    Particle particle_1 {};
    Particle particle_2 {};
    if (!(std::cin >> std::get<0>(particle_1) >> std::get<1>(particle_1)
            >> std::get<2>(particle_1) >> std::get<3>(particle_1)
            >> std::get<0>(particle_2) >> std::get<1>(particle_2)
            >> std::get<2>(particle_2) >> std::get<3>(particle_2))) {
        std::cerr << "expected two particles: x y z mass x y z mass" << std::endl;
        return 1;
    }

    std::cout << "particle 1: ";
    print_particle(particle_1);
    std::cout << std::endl;
    std::cout << "particle 2: ";
    print_particle(particle_2);
    std::cout << std::endl;
    std::cout << "distance = " << distance(particle_1, particle_2) << std::endl;

    return 0;
}
