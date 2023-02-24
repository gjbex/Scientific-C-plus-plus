#ifndef SIMPLE_STATS_HDR
#define SIMPLE_STATS_HDR

#include <iostream>

class SimpleStats {
    private:
        double sum_;
        int n_;
    public:
        SimpleStats() : sum_ {0.0}, n_ {0} {};
        void add(double x) { sum_ += x; n_++; };
        double sum() const { return sum_; };
        int n() const { return n_; };
        double mean() const { return sum()/n(); };
        friend std::ostream& operator<<(std::ostream& out,
                                        const SimpleStats& stats);
};

#endif
