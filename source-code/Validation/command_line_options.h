#ifndef COMMAND_LINE_OPTIONS_H
#define COMMAND_LINE_OPTIONS_H

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

SimulationOptions parse_options(int argc, char* argv[], const char* program_name);

#endif
