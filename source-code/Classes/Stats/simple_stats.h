#ifndef SIMPLE_STATS_HDR
#define SIMPLE_STATS_HDR

#include <iostream>
#include <stdexcept>

class SimpleStats {
    private:
        double sum_{};
        int n_{};
    public:
        SimpleStats() = default;
        void add(double x) { sum_ += x; n_++; };
        double sum() const { return sum_; };
        int n() const { return n_; };
        double mean() const {
            if (n_ == 0) {
                throw std::domain_error("SimpleStats::mean(): no data");
            }
            return sum_ / n_;
        };
        friend std::ostream& operator<<(std::ostream& out,
                                        const SimpleStats& stats);
};

#endif
