#include <iostream>
#include "ocean_view.h"

int main() {
    std::vector<int64_t> buildings {1, 9, 6, 8, 6, 3, 3};
    auto result = ocean_view(buildings);
    std::cout << "Result size: " << result.size() << '\n';
    for (const auto& i : result) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    result = ocean_view2(buildings);
    std::cout << "Result size: " << result.size() << '\n';
    for (const auto& i : result) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}
