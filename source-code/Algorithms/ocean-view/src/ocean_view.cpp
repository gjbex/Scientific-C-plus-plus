#include <algorithm>
#include <random>
#include "ocean_view.h"

std::vector<int64_t> create_buildings(int64_t n, int64_t max_height, int64_t seed) {
    std::mt19937_64 gen(seed);
    std::uniform_int_distribution<int64_t> dist(1, max_height);
    std::vector<int64_t> buildings;
    for (int64_t i = 0; i < n; ++i) {
        buildings.push_back(dist(gen));
    }
    return buildings;
}

std::vector<int64_t> ocean_view(const std::vector<int64_t>& buildings) {
    std::vector<int64_t> result;
    auto previous_highest_building {0};
    for (int64_t i = std::ssize(buildings) - 1; i >= 0 ; --i) {
        if (buildings[i] > previous_highest_building) {
            result.push_back(i);
            previous_highest_building = buildings[i];
        }
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::vector<int64_t> ocean_view2(const std::vector<int64_t>& buildings) {
    std::vector<int64_t> result;
    for (int64_t i = 0; i < std::ssize(buildings); ++i) {
        // Maintain the result as monotonic stack
        while (!result.empty() && 
               buildings[result.back()] <= buildings[i])
            result.pop_back();
        result.push_back(i);
    }
    return result;
}
