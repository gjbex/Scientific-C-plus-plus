#include <iostream>
#include "stats_functional.h"

int main() {
    double value;
    auto stats_pos = create_stats();
    auto stats_neg = create_stats();;
    while (std::cin >> value) {
        if (value >= 0.0) {
            auto [mean, n] = stats_pos(value);
            std::cout << "pos," << n << "," << mean << "\n";
        } else {
            auto [mean, n] = stats_neg(value);
            std::cout << "neg," << n << "," << mean << "\n";
        }
    }
    return 0;
}

