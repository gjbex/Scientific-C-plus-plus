#include <array>
#include <iostream>
#include <numeric>

int main() {
    constexpr std::size_t nr_values {10};
    std::array<double, nr_values> values {};
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (!(std::cin >> values[i])) {
            std::cerr << "expected " << nr_values << " floating-point values" << std::endl;
            return 1;
        }
    }

    double extra_value {};
    if (std::cin >> extra_value) {
        std::cerr << "too many input values, expected exactly " << nr_values << std::endl;
        return 1;
    }

    std::array<double, nr_values> squared_values {};
    for (std::size_t i = 0; i < values.size(); ++i) {
        squared_values[i] = values[i]*values[i];
    }

    const double sum = std::accumulate(squared_values.cbegin(), squared_values.cend(), 0.0);
    std::cout << "sum of squared values = " << sum << std::endl;

    return 0;
}
