#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

struct Particle {
    double x, y, mass;
};

std::vector<Particle> init_particles(size_t n);
std::ostream& operator<<(std::ostream& out, const Particle& particle);
bool mass_cmp(const Particle& p1, const Particle& p2);
bool dist_cmp(const Particle& p1, const Particle& p2);
double distance(const Particle& p);

int main() {
    const size_t n {5};
    std::vector<Particle> particles = init_particles(n);
    std::cout << "original:" << std::endl;
    for (const auto& particle: particles)
        std::cout << particle << std::endl;
    std::sort(particles.begin(), particles.end(), mass_cmp);
    std::cout << "sorted by mass:" << std::endl;
    for (const auto& particle: particles)
        std::cout << particle << std::endl;
    std::sort(particles.begin(), particles.end(), dist_cmp);
    std::cout << "sorted by distance from origin:" << std::endl;
    for (const auto& particle: particles)
        std::cout << particle << " at " << distance(particle) << std::endl;
    return 0;
}

std::vector<Particle> init_particles(size_t n) {
    std::vector<Particle> particles;
    std::mt19937_64 engine;
    auto pos_distr = std::bind(std::normal_distribution<double>(0.0, 1.0),
                          std::ref(engine));
    auto mass_distr = std::bind(std::uniform_real_distribution<double>(0.1, 1.0),
                           std::ref(engine));
    for (size_t i = 0; i < n; i++) {
        Particle particle {pos_distr(), pos_distr(), mass_distr()};
        particles.push_back(particle);
    }
    return particles;
}

std::ostream& operator<<(std::ostream& out, const Particle& particle) {
    return out << "(" << particle.x << ", " << particle.y << "): "
               << particle.mass;
}

bool mass_cmp(const Particle& p1, const Particle& p2) {
    return p1.mass < p2.mass;
}

double distance(const Particle& p) {
    return p.x*p.x + p.y*p.y;
}

bool dist_cmp(const Particle& p1, const Particle& p2) {
    return distance(p1) < distance(p2);
}

