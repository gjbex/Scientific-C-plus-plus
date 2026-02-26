#include <cmath>
#include <functional>
#include <iostream>
#include <random>

struct Particle {
    private:
        double x_, y_, z_;
        double mass_;
    public:
        Particle(std::function<double()> pos_distr,
                 std::function<double()> mass_distr) :
            x_ {pos_distr()},
            y_ {pos_distr()},
            z_ {pos_distr()},
            mass_ {mass_distr()} {};
        double x() const { return x_; }
        double y() const { return y_; }
        double z() const { return z_; }
        double mass() const {return mass_; }
        void move(double dx, double dy, double dz);
        double dist(const Particle& other) const;
        friend std::ostream& operator<<(std::ostream& out, const Particle& p);
};


int main() {
    auto engine {std::mt19937_64(1234)};
    auto pos_distr = std::bind(std::uniform_real_distribution<double>(-1.0, 1.0),
                          std::ref(engine));
    auto mass_distr = std::bind(std::uniform_real_distribution<double>(0.0, 1.0),
                           std::ref(engine));
    Particle p1(pos_distr, mass_distr);
    Particle p2(pos_distr, mass_distr);
    std::cout << p1 << std::endl << p2 << std::endl;
    p1.move(0.5, 0.5, 0.5);
    std::cout << "moved: " << p1 << std::endl;
    std::cout << "x = " << p1.x() << ", y = " << p1.y() << ", z = " << p1.z()
         << std::endl;
    std::cout << "distance = " << p1.dist(p2) << std::endl;
    return 0;
}

inline double sqr(double x) {
    return x*x;
}

void Particle::move(double dx, double dy, double dz) {
    x_ += dx;
    y_ += dy;
    z_ += dz;
}

double Particle::dist(const Particle& other) const {
    return sqrt(sqr(x_ - other.x()) + 
                sqr(y_ - other.y()) +
                sqr(z_ - other.z()));
}

std::ostream& operator<<(std::ostream& out, const Particle& p) {
    return out << "(" << p.x_ << ", " << p.y_ << ", " << p.z_ << ")"
           << ", mass = " << p.mass_;
}
