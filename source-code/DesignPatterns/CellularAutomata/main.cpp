#include <iostream>
#include <memory>

#include "cells.h"
#include "cycle_finder.h"
#include "cyclic_boundary_dynamics.h"
#include "rule.h"
#include "utils.h"
#include "visualization_runner.h"


int main(int argc, char* argv[]) {
    auto options = parse_arguments(argc, argv);
    auto factory = create_cells_factory(options);
    auto cells = factory->create();
    auto rule = create_rule(options.rule_nr);
    /*
    auto dynamics {
        std::make_unique<PrintDecorator>(std::make_unique<CyclicBoundaryDynamics>(rule, cells.size()))
    };
    CycleFinder runner;
    print_cells(cells);
    runner.run(*dynamics, cells);
    auto result = runner.result();
    std::cout << "Cycle size: " << result.cycle_size << std::endl;
    */
    CyclicBoundaryDynamics dynamics(rule, cells.size());
    VisualizationRunner runner(options.t_max);
    runner.run(dynamics, cells);
    return 0;
}
