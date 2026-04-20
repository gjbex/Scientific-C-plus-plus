#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <tuple>

#include <toml++/toml.hpp>

using Options = std::tuple<int, double, double, std::size_t>;

Options get_options(const std::filesystem::path& config_path);

int main(int argc, char* argv[]) {
    const auto config_path = argc > 1 ? std::filesystem::path{argv[1]} : std::filesystem::path{"config.toml"};

    try {
        auto [n, a, b, seed] = get_options(config_path);

        std::mt19937 engine(static_cast<std::mt19937::result_type>(seed));
        std::uniform_real_distribution<double> distr(a, b);
        for (int i = 0; i < n; ++i)
            std::cout << distr(engine) << '\n';
    }
    catch (const toml::parse_error& err) {
        std::cerr << "TOML parse error:\n" << err << '\n';
        return 1;
    }
    catch (const std::exception& err) {
        std::cerr << "Configuration error: " << err.what() << '\n';
        return 1;
    }

    return 0;
}

Options get_options(const std::filesystem::path& config_path) {
    const int default_n{1};
    const double default_a{0.0};
    const double default_b{1.0};

    auto config = toml::parse_file(config_path.string());
    const auto& random = config["random"];

    if (!random.is_table()) {
        throw std::runtime_error{"missing [random] table in " + config_path.string()};
    }

    const int n = random["n"].value_or(default_n);
    const double a = random["a"].value_or(default_a);
    const double b = random["b"].value_or(default_b);

    const auto seed = random["seed"].value<std::size_t>();
    if (!seed) {
        throw std::runtime_error{"missing required integer 'random.seed' in " + config_path.string()};
    }

    return std::make_tuple(n, a, b, *seed);
}
