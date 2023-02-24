#include <iostream>
#include <ranges>
#include <vector>

int main() {
    std::vector<int> data {1, 2, 3, 4, 5, 6, 9};
    auto even = [] (int i) { return i % 2 == 0; };
    auto square = [] (int i) { return i*i; };

    for (int i: data | std::views::filter(even) | std::views::transform(square)) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}
