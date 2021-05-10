#ifndef STATS_FUNCITONAL_HDR
#define STATS_FUNCITONAL_HDR

#include <memory>

auto create_stats() {
    auto sum = std::make_shared<double>(0.0);
    auto n = std::make_shared<size_t>(0);
    return [=] (double value) {
        *sum += value;
        ++(*n);
        return std::make_tuple(*sum/(*n), *n);
    };
}

#endif
