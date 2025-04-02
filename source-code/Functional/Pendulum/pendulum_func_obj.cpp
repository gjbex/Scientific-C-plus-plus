#include <cmath>
#include <numbers>

#include "pendulum_utils.h"

class Pendulum {
    private:
        double freq_;
        const double pi {std::numbers::pi};
    public:
        explicit Pendulum(const double& freq) : freq_ {freq} {};
        double operator()(const double& t) const {
            return cos(2.0*pi*freq_*t);
        };
        double freq() const { return freq_; };
};

int main(int argc, char *argv[]) {
    double freq, delta_t, max_t;
    std::tie(freq, delta_t, max_t) = get_parameters(argc, argv);
    Pendulum pendulum {freq};
    integrate(pendulum, delta_t, max_t);
    return 0;
}
