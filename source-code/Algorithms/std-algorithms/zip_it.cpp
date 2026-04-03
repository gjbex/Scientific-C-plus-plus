#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 {1, 3, 5, 7};
    std::vector<int> v2 {2, 4, 8, 10};
    std::vector<int> v3(4, 0);
    std::transform(v1.cbegin(), v1.cend(), v2.cbegin(), v3.begin(),
            [] (int x, int y) { return x + y; });
    for (const auto& x: v1)
        std::cout << x << " ";
    std::cout << std::endl;
    for (const auto& x: v2)
        std::cout << x << " ";
    std::cout << std::endl;
    for (const auto& x: v3)
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
