#include "counter.h"
#include <cstdint>
#include <iostream>
#include <span>

int main() {
    Counter<int, std::uint32_t> counter(-3, 5);
    std::cout << "domain: " << counter.lower << " -> " << counter.upper << "\n";
    int values[] {-2, -3, -3, 5, 2, 5, 2, 2, 2};
    std::cout << "values:";
    for (auto const& value: std::span<int>(values)) {
        std::cout << " " << value;
        counter.incr(value);
    }
    std::cout << "\n";
    for (auto const& [value, count]: counter) {
        std::cout << value << " " << count << "\n";
    }
    return 0;
}
