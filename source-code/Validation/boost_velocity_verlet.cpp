#include "command_line_options.h"

#include <algorithm>
#include <array>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>

#include <boost/numeric/odeint/stepper/velocity_verlet.hpp>

using coordinate_type = std::array<double, 1>;
using velocity_type = std::array<double, 1>;
using state_type = std::pair<coordinate_type, velocity_type>;
using stepper_type = boost::numeric::odeint::velocity_verlet<coordinate_type>;

double energy(const state_type& state, const OscillatorParameters& parameters) {
    const double m {parameters.mass};
    const double k {parameters.spring_constant};
    const double x {state.first[0]};
    const double v {state.second[0]};
    const double kinetic {0.5*m*v*v};
    const double potential {0.5*k*x*x};
    return kinetic + potential;
}

struct HarmonicOscillator {
    private:
        OscillatorParameters parameters_;

    public:
        explicit HarmonicOscillator(OscillatorParameters parameters) :
            parameters_ {parameters} {}

        void operator()(const coordinate_type& q, const velocity_type&,
                        coordinate_type& acceleration, const double) const {
            const double m {parameters_.mass};
            const double k {parameters_.spring_constant};
            const double x {q[0]};
            acceleration[0] = -(k/m)*x;
        }
};

int main(int argc, char* argv[]) {
    try {
        const SimulationOptions options {parse_options(argc, argv, "boost_velocity_verlet.exe")};
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
