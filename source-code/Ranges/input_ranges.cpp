#include <algorithm>
#include <iostream>
#include <iterator>
#include <ranges>

int main() {
    std::ranges::copy(
            std::ranges::istream_view<double>(std::cin)
                | std::views::filter([] (double x) { return x > 0.0; })
                | std::views::transform([] (double x) { return x*x; }),
            std::ostream_iterator<double>(std::cout, "\n")
            );
    return 0;
}
