#include "command_line_options.h"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

struct State {
    double x {1.0};
    double v {0.0};
};

double acceleration(const State& state, const OscillatorParameters& parameters) {
    const double m {parameters.mass};
    const double k {parameters.spring_constant};
    const double x {state.x};
    return -(k/m)*x;
}

double energy(const State& state, const OscillatorParameters& parameters) {
    const double m {parameters.mass};
    const double k {parameters.spring_constant};
    const double x {state.x};
    const double v {state.v};
    const double kinetic {0.5*m*v*v};
    const double potential {0.5*k*x*x};
    return kinetic + potential;
}

State explicit_euler_step(const State& state, const OscillatorParameters& parameters,
                          const double dt) {
    const double x {state.x};
    const double v {state.v};
    const double a {acceleration(state, parameters)};
    return State {
        x + dt*v,
        v + dt*a,
    };
}

int main(int argc, char* argv[]) {
    try {
        const SimulationOptions options {parse_options(argc, argv, "explicit_euler.exe")};
        State state {options.x0, options.v0};
        const double initial_energy {energy(state, options.parameters)};
        if (initial_energy == 0.0) {
            throw std::runtime_error("initial energy is zero; choose a non-zero x0 or v0");
        }
        double max_relative_energy_error {0.0};

        std::cout << "# explicit Euler harmonic oscillator\n";
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
                      << state.x << '\t'
                      << state.v << '\t'
                      << current_energy << '\t'
                      << relative_energy_error << '\n';

            state = explicit_euler_step(state, options.parameters, options.dt);
        }

        std::cerr << "maximum relative energy error: "
                  << max_relative_energy_error << '\n';
        std::cerr << "validation note: energy should be conserved for this model; "
                  << "explicit Euler shows numerical energy drift.\n";
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        return 1;
    }
    return 0;
}
