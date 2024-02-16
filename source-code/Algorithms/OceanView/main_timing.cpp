#include <iostream>
#include "ocean_view.h"

int main() {
    std::vector<int64_t> buildings {create_buildings(1000000, 100, 1234)};
    auto result = ocean_view(buildings);
    std::cout << "Result size: " << result.size() << '\n';
    return 0;
}
