#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

struct OscillatorParameters {
    double mass {1.0};
    double spring_constant {1.0};
};

struct State {
    double x {1.0};
    double v {0.0};
};

struct SimulationOptions {
    double dt {0.05};
    int steps {400};
    OscillatorParameters parameters {};
    State initial_state {};
};

double acceleration(const State& state, const OscillatorParameters& parameters) {
    return -(parameters.spring_constant/parameters.mass)*state.x;
}

double energy(const State& state, const OscillatorParameters& parameters) {
    const double kinetic {0.5*parameters.mass*state.v*state.v};
    const double potential {0.5*parameters.spring_constant*state.x*state.x};
    return kinetic + potential;
}

State explicit_euler_step(const State& state, const OscillatorParameters& parameters,
                          const double dt) {
    return State {
        state.x + dt*state.v,
        state.v + dt*acceleration(state, parameters),
    };
}

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
            "usage: explicit_euler.exe [dt steps mass spring_constant x0 v0]"
        };
    }
    if (argc == 7) {
        options.dt = parse_double(argv[1], "dt");
        options.steps = parse_int(argv[2], "steps");
        options.parameters.mass = parse_double(argv[3], "mass");
        options.parameters.spring_constant = parse_double(argv[4], "spring_constant");
        options.initial_state.x = parse_double(argv[5], "x0");
        options.initial_state.v = parse_double(argv[6], "v0");
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
        State state {options.initial_state};
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
                  << ", x0 = " << options.initial_state.x
                  << ", v0 = " << options.initial_state.v << '\n';
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
