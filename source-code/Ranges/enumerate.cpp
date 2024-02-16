#include <iostream>
#include <map>
#include <ranges>
#include <vector>

int main() {
    std::vector<char> data {'a', 'b', 'd', 'z'};
    for (const auto [id, value]: std::views::enumerate(data)) {
        std::cout << id << " -> " << value << "\n";
    }
    return 0;
}
