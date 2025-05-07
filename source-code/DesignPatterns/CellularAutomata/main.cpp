#include <iostream>
#include <memory>

#include "cells.h"
#include "cycle_finder.h"
#include "cyclic_boundary_dynamics.h"
#include "rule.h"
#include "utils.h"


int main(int argc, char* argv[]) {
    auto options = parse_arguments(argc, argv);
    auto factory = create_factor(options);
    Cells cells = factory->create();
    auto rule = create_rule(options.rule_nr);
    PrintDecorator<CyclicBoundaryDynamics> dynamics(CyclicBoundaryDynamics(rule, cells.size()));
    CycleFinder runner;
    print_cells(cells);
    runner.run(dynamics, cells);
    std::cout << "Cycle size: " << runner.cycle_size() << std::endl;
    return 0;
}
