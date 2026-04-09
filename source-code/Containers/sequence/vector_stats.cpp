#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

double compute_mean(const std::vector<double>& values) {
    double sum {0.0};
    for (const auto value: values) {
        sum += value;
    }
    return sum/static_cast<double>(values.size());
}

double compute_median(std::vector<double> values) {
    std::sort(values.begin(), values.end());
    const std::size_t mid = values.size()/2;
    if (values.size() % 2 == 0) {
        return 0.5*(values[mid - 1] + values[mid]);
    }
    return values[mid];
}

int main() {
    std::vector<double> values;
    double value {};
    while (std::cin >> value) {
        values.push_back(value);
    }

    if (values.empty()) {
        std::cerr << "no data provided" << std::endl;
        return 1;
    }

    const auto [min_it, max_it] = std::minmax_element(values.cbegin(), values.cend());
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "count   = " << values.size() << std::endl;
    std::cout << "min     = " << *min_it << std::endl;
    std::cout << "max     = " << *max_it << std::endl;
    std::cout << "average = " << compute_mean(values) << std::endl;
    std::cout << "median  = " << compute_median(values) << std::endl;

    return 0;
}
