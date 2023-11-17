#ifndef OCEAN_VIEW_HDR
#define OCEAN_VIEW_HDR

#include <cstdint>
#include <vector>

std::vector<int64_t> create_buildings(int64_t n, int64_t max_height, int64_t seed);
std::vector<int64_t> ocean_view(const std::vector<int64_t>& buildings);
std::vector<int64_t> ocean_view2(const std::vector<int64_t>& buildings);

#endif // OCEAN_VIEW_HDR
