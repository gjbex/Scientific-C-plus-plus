#include <boost/program_options.hpp>
#include <boost/tokenizer.hpp>
#include <iostream>
#include <ranges>
#include <vector>

using separator = boost::char_separator<char>;

/**
 * @brief Function to handle command line arguments.
 *
 * The application expects an optional argument for the separator character(s).
 * If not provided, it defaults to a comma.
 *
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return The separator character(s) as a string.
 */
std::string handle_arguments(int argc, char* argv[]) {
    namespace po = boost::program_options;
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "produce help message")
        ("separator,s", po::value<std::string>()->default_value(","), "separator character(s)");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << "\n";
        exit(0);
    }

    return vm["separator"].as<std::string>();
}

int main(int argc, char* argv[]) {
    std::string sep_str = handle_arguments(argc, argv);
    separator sep(sep_str.c_str(), sep_str.c_str() + sep_str.size());
    std::vector<std::string> column_names;
    std::string line;
    if (std::getline(std::cin, line)) {
        boost::tokenizer<separator> tokenizer(line, sep);
        for (auto it = tokenizer.begin(); it != tokenizer.end(); ++it) {
            column_names.push_back(*it);
        }
    }
    std::vector<double> sums(column_names.size(), 0.0);
    while (std::getline(std::cin, line)) {
        boost::tokenizer<separator> tokenizer(line, sep);
        for (const auto& [i, token]: std::views::enumerate(tokenizer)) {
            sums[i] += std::stod(token);
        }
    }
    for (const auto& [name, sum]: std::views::zip(column_names, sums)) {
        std::cout << name << " " << sum << '\n';
    }
    return 0;
}
