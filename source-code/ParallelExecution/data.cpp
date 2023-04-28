#include <limits>
#include <random>
#include "data.h"

std::vector<int> create_data(const size_t size) {
    return create_data(size, std::numeric_limits<int>::max());
}

std::vector<int> create_data(const size_t size, int max_value) {
    std::mt19937_64 engine;
    std::uniform_int_distribution<int> distr(0, max_value);
    std::vector<int> data;
    for (size_t i {0}; i < size; ++i) {
        data.push_back(distr(engine));
    }
    return data;
}
