#include <boost/program_options.hpp>
#include <fstream>
#include <iostream>

/* @brief parse the command line arguments
 *
 * Function that parses the command line arguments for this applicaiton.
 * The application expects two arguments: the name of the file to read,
 * and the number of rows and columns of the matrix stored in that file.
 *
 * The Boost library is used to parse the command line arguments.
 *
 * @param argc the number of command line arguments
 * @param argv the command line arguments
 *
 * @return the name of the file to read and the number of rows and columns
 * of the matrix as a tuple.
 */
std::tuple<std::string, int, int> parse_arguments(int argc, char* argv[]) {
    namespace po = boost::program_options;
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("file", po::value<std::string>(), "the file to read")
        ("rows", po::value<int>(), "the number of rows of the matrix")
        ("columns", po::value<int>(), "the number of columns of the matrix");
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    if (vm.count("help") || !vm.count("file") || !vm.count("columns")) {
        std::cout << desc << std::endl;
        std::exit(1);
    }
    return std::make_tuple(vm["file"].as<std::string>(), vm["rows"].as<int>(), vm["columns"].as<int>());
}

int main(int argc, char* argv[]) {
    auto [filename, rows, columns] = parse_arguments(argc, argv);
    std::ifstream file(filename, std::ios::in | std::ios::binary);
    if (!file) {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        std::exit(2);
    }
    for (int row_nr = 0; row_nr < rows; ++row_nr) {
        for (int col_nr = row_nr; col_nr < columns; ++col_nr) {
            double value;
            file.read(reinterpret_cast<char*>(&value), sizeof(double));
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    file.close();
    return 0;
}
