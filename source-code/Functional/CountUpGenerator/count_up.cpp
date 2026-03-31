#include <cstdint>
#include <generator>
#include <functional>
#include <iostream>
#include <utility>


auto create_count_up_geneartor(const uint64_t max_value) {
    return [max_value] () -> std::generator<uint64_t> {
        uint64_t current_value {0};
        while (current_value < max_value) {
            co_yield current_value;
            current_value++;
        }
    };
}

int main() {
    auto geneartor {create_count_up_geneartor(10)};
    for (auto i : geneartor()) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}
