#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

#include <boost/numeric/odeint/stepper/velocity_verlet.hpp>

struct OscillatorParameters {
    double mass {1.0};
    double spring_constant {1.0};
};

struct SimulationOptions {
    double dt {0.05};
    int steps {400};
    OscillatorParameters parameters {};
    double x0 {1.0};
    double v0 {0.0};
};

using coordinate_type = std::array<double, 1>;
using velocity_type = std::array<double, 1>;
using state_type = std::pair<coordinate_type, velocity_type>;
using stepper_type = boost::numeric::odeint::velocity_verlet<coordinate_type>;

double energy(const state_type& state, const OscillatorParameters& parameters) {
    const double x {state.first[0]};
    const double v {state.second[0]};
    const double kinetic {0.5*parameters.mass*v*v};
    const double potential {0.5*parameters.spring_constant*x*x};
    return kinetic + potential;
}

class HarmonicOscillator {
    private:
        OscillatorParameters parameters_;

    public:
        explicit HarmonicOscillator(OscillatorParameters parameters) :
            parameters_ {parameters} {}

        void operator()(const coordinate_type& q, const velocity_type&,
                        coordinate_type& acceleration, const double) const {
            acceleration[0] = -(parameters_.spring_constant/parameters_.mass)*q[0];
        }
};

double parse_double(const char* value, const std::string& name) {
    char* end {};
    const double result {std::strtod(value, &end)};
    if (end == value || *end != '\0') {
        throw std::runtime_error("invalid floating-point value for " + name + ": " + value);
    }
    return result;
}

int parse_int(const char* value, const std::string& name) {
    char* end {};
    const long result {std::strtol(value, &end, 10)};
    if (end == value || *end != '\0') {
        throw std::runtime_error("invalid integer value for " + name + ": " + value);
    }
    if (result < 0) {
        throw std::runtime_error(name + " must be non-negative");
    }
    return static_cast<int>(result);
}

SimulationOptions parse_options(const int argc, char* argv[]) {
    SimulationOptions options {};
    if (argc != 1 && argc != 7) {
        throw std::runtime_error {
            "usage: boost_velocity_verlet.exe [dt steps mass spring_constant x0 v0]"
        };
    }
    if (argc == 7) {
        options.dt = parse_double(argv[1], "dt");
        options.steps = parse_int(argv[2], "steps");
        options.parameters.mass = parse_double(argv[3], "mass");
        options.parameters.spring_constant = parse_double(argv[4], "spring_constant");
        options.x0 = parse_double(argv[5], "x0");
        options.v0 = parse_double(argv[6], "v0");
    }
    if (options.dt <= 0.0) {
        throw std::runtime_error("dt must be positive");
    }
    if (options.parameters.mass <= 0.0) {
        throw std::runtime_error("mass must be positive");
    }
    if (options.parameters.spring_constant <= 0.0) {
        throw std::runtime_error("spring_constant must be positive");
    }
    return options;
}

int main(int argc, char* argv[]) {
    try {
        const SimulationOptions options {parse_options(argc, argv)};
        state_type state {
            coordinate_type {options.x0},
            velocity_type {options.v0},
        };
        const double initial_energy {energy(state, options.parameters)};
        if (initial_energy == 0.0) {
            throw std::runtime_error("initial energy is zero; choose a non-zero x0 or v0");
        }

        HarmonicOscillator oscillator {options.parameters};
        stepper_type stepper;
        double max_relative_energy_error {0.0};

        std::cout << "# Boost.Odeint velocity Verlet harmonic oscillator\n";
        std::cout << "# dt = " << options.dt
                  << ", steps = " << options.steps
                  << ", mass = " << options.parameters.mass
                  << ", spring_constant = " << options.parameters.spring_constant
                  << ", x0 = " << options.x0
                  << ", v0 = " << options.v0 << '\n';
        std::cout << "t\tx\tv\tenergy\trelative_energy_error\n";
        std::cout << std::setprecision(16);

        for (int step_nr {0}; step_nr <= options.steps; ++step_nr) {
            const double t {step_nr*options.dt};
            const double current_energy {energy(state, options.parameters)};
            const double relative_energy_error {
                std::abs(current_energy - initial_energy)/initial_energy
            };
            max_relative_energy_error = std::max(max_relative_energy_error,
                                                 relative_energy_error);

            std::cout << t << '\t'
                      << state.first[0] << '\t'
                      << state.second[0] << '\t'
                      << current_energy << '\t'
                      << relative_energy_error << '\n';

            stepper.do_step(oscillator, state, t, options.dt);
        }

        std::cerr << "maximum relative energy error: "
                  << max_relative_energy_error << '\n';
        std::cerr << "validation note: velocity Verlet is symplectic; "
                  << "for this model the energy error stays bounded instead of drifting.\n";
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
