#include <cmath>
#include <functional>
#include <iostream>
#include <random>

using std::sqrt;


enum class Charge {negative = -1, positive = 1};

class Particle {
    private:
        double x_, y_, z_;
        double mass_;
        Charge charge_;
    public:
        Particle(std::function<double()> pos_distr,
                 std::function<double()> mass_distr,
                 std::function<int()> charge_distr) :
            x_ {pos_distr()},
            y_ {pos_distr()},
            z_ {pos_distr()},
            mass_ {mass_distr()},
            charge_ {charge_distr() == 0 ? Charge::negative :
                                           Charge::positive}
            {};
        double x() const { return x_; }
        double y() const { return y_; }
        double z() const { return z_; }
        double mass() const {return mass_; }
        Charge charge() const {return charge_; }
        int charge_val() const {return (int) charge_; }
        void move(double dx, double dy, double dz);
        double dist(const Particle& other) const;
        double e_force(const Particle& other) const;
        friend std::ostream& operator<<(std::ostream& out, const Particle& p);
};

std::ostream& operator<<(std::ostream& out, const Particle& p);

int main() {
    auto engine {std::mt19937_64(1234)};
    auto pos_distr = std::bind(std::uniform_real_distribution<double>(-1.0, 1.0),
                          std::ref(engine));
    auto mass_distr = std::bind(std::uniform_real_distribution<double>(0.0, 1.0),
                           std::ref(engine));
    auto charge_distr = std::bind(std::uniform_int_distribution<int>(0, 1),
                             std::ref(engine));
    Particle p1(pos_distr, mass_distr, charge_distr);
    Particle p2(pos_distr, mass_distr, charge_distr);
    std::cout << p1 << std::endl << p2 << std::endl;
    p1.move(0.5, 0.5, 0.5);
    std::cout << "moved: " << p1 << std::endl;
    std::cout << "x = " << p1.x() << ", y = " << p1.y() << ", z = " << p1.z()
         << std::endl;
    std::cout << "distance = " << p1.dist(p2) << std::endl;
    std::cout << "force = " << p1.e_force(p2) << std::endl;
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

double Particle::e_force(const Particle& other) const {
    double q_e {1.6021e-19};
    const double k_c {8.98755e9};
    const double r {dist(other)};
    return -k_c*charge_val()*other.charge_val()*sqr(q_e/r);
}

std::ostream& operator<<(std::ostream& out, const Particle& p) {
    return out << "(" << p.x() << ", " << p.y() << ", " << p.z() << ")"
           << ", mass = " << p.mass()
           << ", charge = " << p.charge_val();
}
