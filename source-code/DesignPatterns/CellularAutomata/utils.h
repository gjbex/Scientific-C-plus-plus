#ifndef UTILS_HDR
#define UTILS_HDR

#include <cstdint>
#include <memory>
#include <optional>
#include <string>

#include "cells_factory.h"

struct CAOptions {
    std::size_t nr_cells;
    std::string initializer;
    std::optional<std::size_t> seed;
    int rule_nr;
    int t_max;
};

CAOptions parse_arguments(int argc, char* argv[]);
std::unique_ptr<CellsFactory> create_factory(const CAOptions& options);

#endif
