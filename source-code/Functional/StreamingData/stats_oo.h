#ifndef STATS_OO_HDR
#define STATS_OO_HDR

#include <tuple>

class Stats {
    private:
        double sum_ {0.0};
        size_t n_ {0};
    public:
        auto operator()(const double value) {
            sum_ += value;
            ++n_;
            return std::make_tuple(sum_/n_, n_);
        }
};

#endif
