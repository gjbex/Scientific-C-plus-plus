#include "command_line_options.h"

#include <cstdlib>
#include <stdexcept>
#include <string>

namespace {

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

}

SimulationOptions parse_options(const int argc, char* argv[], const char* program_name) {
    SimulationOptions options {};
    if (argc != 1 && argc != 7) {
        throw std::runtime_error {
            "usage: " + std::string {program_name} +
            " [dt steps mass spring_constant x0 v0]"
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
