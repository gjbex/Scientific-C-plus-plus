#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>
#include "function_factory.h"

/**
 * @brief Parse command line arguments.
 *
 * This function uses the Boost Program Options library to define and parse command line arguments.
 * The arguments are:
 *   - `--degree`: The degree of the polynomial (default: 2).
 *   - `--nr-functions`: The number of functions to generate (default: 1).
 *   - `--base-file-name`: The base filename for the output files (default: "output").
 *   - `--seed`: The seed for the random number generator (default: 1234).
 *
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return A tuple containing the degree of the polynomial, 
 *         the number of functions to generate, the base name for the output files,
 *         and the seed for the random number generator.
 */
auto parse_arguments(int argc, char* argv[]) {
    namespace po = boost::program_options;
    int degree {2};
    int nr_functions {1};
    std::string base_file_name {"output"};
    std::size_t seed {1234};

    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("degree,d", po::value<int>(&degree)->default_value(2), "degree of the polynomial")
        ("nr-functions,n", po::value<int>(&nr_functions)->default_value(1), "number of functions to generate")
        ("base-file-name,b", po::value<std::string>(&base_file_name)->default_value("output"), "base filename for output files")
        ("seed,s", po::value<std::size_t>(&seed)->default_value(1234), "seed for random number generator");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        exit(0);
    }

    return std::make_tuple(degree, nr_functions, base_file_name, seed);
}

/**
 * @brief Compute values of a given function in a given interval, writing the argument and function
 * values to a file.
 *
 * @param function The function to compute values for.
 * @params x_min The minimum value of the interval.
 * @param x_max The maximum value of the interval.
 * @param x_delta The step size for the interval.
 * @param file_name The name of the file to write the values to.
 */
void write_function(const FunctionFactory<double>::Function& function,
                   double x_min, double x_max, double x_delta,
                   const std::string& file_name) {
    std::ofstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << file_name << "\n";
        std::exit(1);
    }

    for (double x = x_min; x <= x_max; x += x_delta) {
        file << x << " " << function(x) << "\n";
    }
    file.close();
}

int main(int argc, char* argv[]) {
    // Parse command line arguments
    const auto [degree, nr_functions, base_file_name, seed] = parse_arguments(argc, argv);

    // Create a FunctionFactory instance
    FunctionFactory<double> factory(degree, seed);

    // Print the parsed values
    for (int function_nr = 0; function_nr < nr_functions; ++function_nr) {
        auto function = factory.create();
        std::string file_name = base_file_name + std::to_string(function_nr) + ".txt";
        write_function(function, -1.0, 1.0, 0.01, file_name);
    }
    std::cout << "Degree: " << degree << "\n";
    std::cout << "Seed: " << seed << "\n";

    return 0;
}
