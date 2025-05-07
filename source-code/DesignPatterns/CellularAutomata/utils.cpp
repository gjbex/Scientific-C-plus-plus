#include <boost/program_options.hpp>
#include <iostream>

#include "random_cells_factory.h"
#include "uniform_cells_factory.h"
#include "utils.h"

namespace po = boost::program_options;

CAOptions parse_arguments(int argc, char* argv[]) {
    CAOptions options;

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("nr_cells", po::value<int>()->required(), "number of cells (required, >= 0)")
        ("initializer", po::value<std::string>()->default_value("uniform"), "initializer: uniform or random")
        ("seed", po::value<int>(), "random seed (required if initializer is random, >= 0)")
        ("rule_nr", po::value<int>()->required(), "rule number (0-255)")
        ("t_max", po::value<int>()->required(), "number of steps");

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
            if (!vm.count("seed")) {
                throw std::runtime_error("seed is required when initializer is 'random'");
            }
            int seed_raw = vm["seed"].as<int>();
            if (seed_raw < 0) {
                throw std::runtime_error("seed must be >= 0");
            }
            options.seed = static_cast<std::size_t>(seed_raw);
        }

        options.rule_nr = vm["rule_nr"].as<int>();
        if (options.rule_nr < 0 || options.rule_nr > 255) {
            throw std::runtime_error("rule_nr must be between 0 and 255");
        }

        options.t_max = vm["t_max"].as<int>();

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        std::cerr << desc << "\n";
        exit(1);
    }

    return options;
}

std::unique_ptr<CellsFactory> create_factor(const CAOptions& options) {
    if (options.initializer == "uniform") {
        return std::make_unique<UniformCellsFactory>(options.nr_cells);
    } else if (options.initializer == "random") {
        return std::make_unique<RandomCellsFactory>(options.nr_cells, options.seed.value());
    } else {
        throw std::invalid_argument("Unknown initializer: " + options.initializer);
    }
}
