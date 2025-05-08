#include <iostream>
#include <memory>

#include "cells.h"
#include "cycle_finder.h"
#include "cyclic_boundary_dynamics.h"
#include "rule.h"
#include "utils.h"
#include <variant>
#include <type_traits>
#include "visualization_runner.h"


int main(int argc, char* argv[]) {
    auto options = parse_arguments(argc, argv);
    auto factory = create_cells_factory(options);
    auto cells = factory->create();
    auto rule = create_rule(options.rule_nr);
    std::unique_ptr<Dynamics> dynamics {std::make_unique<CyclicBoundaryDynamics>(rule, cells.size())};
    if (options.verbose && options.runner != "visualization") {
        dynamics  = std::make_unique<PrintDecorator>(std::move(dynamics));
    }
    auto runner = create_runner(options);
    std::visit([&](auto& r) {
        r.run(*dynamics, cells);
    }, runner);
    std::visit([&](auto& r) {
        using RunnerT = std::decay_t<decltype(r)>;
        if constexpr (std::is_same_v<RunnerT, CycleFinder>) {
            std::cout << "Cycle size: " << r.cycle_size() << std::endl;
        }
    }, runner);
    return 0;
}
