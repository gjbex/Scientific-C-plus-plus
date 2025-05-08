#ifndef UTILS_HDR
#define UTILS_HDR

#include <cstdint>
#include <memory>
#include <string>

#include "cells_factory.h"

struct CAOptions {
    std::size_t nr_cells;
    std::string initializer;
    std::size_t seed;
    std::string runner;
    int rule_nr;
    int t_max;
};

CAOptions parse_arguments(int argc, char* argv[]);
std::unique_ptr<CellsFactory> create_cells_factory(const CAOptions& options);

#endif
