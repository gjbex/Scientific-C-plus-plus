#include <iostream>
#include <memory>

#include "cells.h"
// #include "cycle_finder.h"
#include "cyclic_boundary_dynamics.h"
#include "rule.h"
#include "utils.h"


int main(int argc, char* argv[]) {
    auto options = parse_arguments(argc, argv);
    auto factory = create_factor(options);
    Cells cells = factory->create();
    auto rule = create_rule(options.rule_nr);
    CyclicBoundaryDynamics dynamics(rule, cells.size());
    PrintDecorator<CyclicBoundaryDynamics> print_dynamics(dynamics);
    print_cells(cells);
    for (int t = 1; t < options.t_max; ++t) {
        print_dynamics.update(cells);
    }
    return 0;
}
