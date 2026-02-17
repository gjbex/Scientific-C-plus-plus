#include <CLI/CLI.hpp>
#include <iostream>
#include <random>

using Options = std::tuple<int, double, double, size_t>;

Options get_options(int argc, char** argv);

int main(int argc, char* argv[]) {
    auto [n, a, b, seed] = get_options(argc, argv);

    std::mt19937 engine(seed);
    std::uniform_real_distribution<double> distr(a, b);
    for (int i = 0; i < n; ++i)
        std::cout << distr(engine) << std::endl;

    return 0;
}

Options get_options(int argc, char** argv) {
    const int default_n {1};
    const double default_a {0.0};
    const double default_b {1.0};
    int n {default_n};
    double a {default_a};
    double b {default_b};
    size_t seed;
    CLI::App app{"Generate random numbers"};
    app.add_option("-n", n, "number of random values to generate")->default_val(std::to_string(default_n));
    app.add_option("-a", a, "minimum value")->default_val(std::to_string(default_a));
    app.add_option("-b", b, "maximum value")->default_val(std::to_string(default_b));
    app.add_option("--seed", seed, "seed to use");
    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        std::exit(app.exit(e));
    }
    return std::make_tuple(n, a, b, seed);
}
