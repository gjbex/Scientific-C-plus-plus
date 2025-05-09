#include <iostream>
#include <stdexcept>

#include "simple_stats.h"
#include "stats.h"

int main() {
    SimpleStats simple_stats;
    Stats stats;
    std::cout << "adding";
    for (int i = 1; i <= 5; ++i) {
        double x {i + 0.1*(i + 1)};
        simple_stats.add(x);
        stats.add(x);
        std::cout << " " << x;
    }
    std::cout << std::endl;
    std::cout << "simple stats: " << std::endl << simple_stats << std::endl;
    std::cout << std::endl;
    std::cout << "stats: " << std::endl << stats << std::endl;
    std::cout << std::endl;
    try {
        std::cout << "mean = " << stats.mean() << std::endl;
        std::cout << "stddev = " << stats.stddev() << std::endl;
    } catch (const std::domain_error& e) {
        std::cerr << "Error computing statistics: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
