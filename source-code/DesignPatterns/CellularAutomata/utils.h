#ifndef UTILS_HDR
#define UTILS_HDR

#include <memory>
#include <string>

#include "cells_factory.h"
#include "cycle_finder.h"
#include "dynamics.h"
#include "runners.h"
#include "visualization_runner.h"


struct CAOptions {
    std::size_t nr_cells;
    std::string initializer;
    std::size_t seed;
    std::string runner;
    int rule_nr;
    int t_max;
    bool verbose;  // enable verbose output
};

CAOptions parse_arguments(int argc, char* argv[]);
std::unique_ptr<CellsFactory> create_cells_factory(const CAOptions& options);
std::unique_ptr<Dynamics> create_dynamics(const CAOptions& options);
RunnerVariant create_runner(const CAOptions& options);
void handle_runner_result(RunnerVariant& runner, const CAOptions& options);

#endif
