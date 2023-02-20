#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int main(int argc __attribute__((unused)),
         char *argv[] __attribute__((unused))) {
    std::vector<int> data {3, 4, 7, 9, 12, 2, 1};
    for (auto value: data)
        std::cout << value << " ";
    std::cout << std::endl;
    auto times2 = [] (int n) -> int { return 2*n; };
    auto filtered = data | std::views::transform(times2);
    auto sum = std::accumulate(filtered.begin(), filtered.end(), 0);
    std::cout << "sum = " << sum << std::endl;
    return 0;
}
