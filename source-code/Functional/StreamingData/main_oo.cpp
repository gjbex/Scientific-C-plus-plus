#include <iostream>
#include "stats_oo.h"

int main() {
    double value;
    Stats stats_pos;
    Stats stats_neg;
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
