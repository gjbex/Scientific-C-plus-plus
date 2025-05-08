#ifndef UTILS_HDR
#define UTILS_HDR

// Standard
#include <cstdint>
#include <memory>
#include <string>
#include <variant>

// Project headers
#include "cells_factory.h"
#include "cycle_finder.h"
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

/// A runner that can either find cycles or visualize dynamics, selected at runtime
using RunnerVariant = std::variant<CycleFinder, VisualizationRunner>;
/// Factory to create the appropriate runner based on command-line options
RunnerVariant create_runner(const CAOptions& options);

#endif
