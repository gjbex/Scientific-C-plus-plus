#include <boost/program_options.hpp>
#include <iostream>
#include <type_traits>

#include "random_cells_factory.h"
#include "uniform_cells_factory.h"
#include "utils.h"
#include "dynamics.h"
#include "cyclic_boundary_dynamics.h"

namespace po = boost::program_options;

CAOptions parse_arguments(int argc, char* argv[]) {
    CAOptions options;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("nr_cells", po::value<int>()->required(), "number of cells (required, > 0)")
        ("initializer", po::value<std::string>()->default_value("random"), "initializer: 'uniform' or 'random'")
        ("seed", po::value<int>()->default_value(1234), "random seed (default value 1234)")
        ("runner", po::value<std::string>()->default_value("visualization"), "runner: 'visualization' or 'cycle_finder'")
        ("t_max", po::value<int>()->default_value(15), "number of steps (>= 0)")
        ("verbose", po::bool_switch(), "enable verbose output")
        ("rule_nr", po::value<int>()->required(), "rule number (0-255)");

    po::variables_map vm;

    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);

        if (vm.count("help")) {
            std::cout << desc << "\n";
            exit(0);
        }

        po::notify(vm);

        int nr_cells_raw = vm["nr_cells"].as<int>();
        if (nr_cells_raw < 0) {
            throw std::runtime_error("nr_cells must be >= 0");
        }
        options.nr_cells = static_cast<std::size_t>(nr_cells_raw);

        options.initializer = vm["initializer"].as<std::string>();
        if (options.initializer != "uniform" && options.initializer != "random") {
            throw std::runtime_error("initializer must be 'uniform' or 'random'");
        }

        if (options.initializer == "random") {
            if (vm.count("seed")) {
                int seed_raw = vm["seed"].as<int>();
                if (seed_raw < 0) {
                    throw std::runtime_error("seed must be >= 0");
                }
                options.seed = static_cast<std::size_t>(seed_raw);
            }
        }

        options.runner = vm["runner"].as<std::string>();
        if (options.runner != "visualization" && options.runner != "cycle_finder") {
            throw std::runtime_error("runner must be 'visualization' or 'cycle_finder'");
        }

        if (options.runner == "visualization") {
            if (!vm.count("t_max")) {
                throw std::runtime_error("t_max must be specified for 'visualization' runner");
            }
            options.t_max = vm["t_max"].as<int>();
            if (options.t_max < 0) {
                throw std::runtime_error("t_max must be positive");
            }
        }

        options.rule_nr = vm["rule_nr"].as<int>();
        if (options.rule_nr < 0 || options.rule_nr > 255) {
            throw std::runtime_error("rule_nr must be between 0 and 255");
        }
        // Read verbose flag
        options.verbose = vm["verbose"].as<bool>();

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        std::cerr << desc << "\n";
        exit(1);
    }

    return options;
}

std::unique_ptr<CellsFactory> create_cells_factory(const CAOptions& options) {
    if (options.initializer == "uniform") {
        return std::make_unique<UniformCellsFactory>(options.nr_cells);
    } else if (options.initializer == "random") {
        return std::make_unique<RandomCellsFactory>(options.nr_cells, options.seed);
    } else {
        throw std::invalid_argument("Unknown initializer: " + options.initializer);
    }
}
 
RunnerVariant create_runner(const CAOptions& options) {
    if (options.runner == "cycle_finder") {
        return CycleFinder{};
    } else if (options.runner == "visualization") {
        return VisualizationRunner{options.t_max};
    } else {
        throw std::invalid_argument("Unknown runner: " + options.runner);
    }
}
 
std::unique_ptr<Dynamics> create_dynamics(const CAOptions& options) {
    auto rule = create_rule(options.rule_nr);
    std::unique_ptr<Dynamics> dyn =
        std::make_unique<CyclicBoundaryDynamics>(rule, options.nr_cells);
    // wrap in print-decorator if verbose requested
    if (options.verbose) {
        dyn = std::make_unique<PrintDecorator>(std::move(dyn));
    }
    return dyn;
}

void handle_runner_result(RunnerVariant& runner, [[maybe_unused]] const CAOptions& options) {
    std::visit([](auto& r) {
        using RunnerT = std::decay_t<decltype(r)>;
        if constexpr (std::is_same_v<RunnerT, CycleFinder>) {
            std::cout << "Cycle size: " << r.cycle_size() << std::endl;
        }
    }, runner);
}
