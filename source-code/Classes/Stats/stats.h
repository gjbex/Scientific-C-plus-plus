#ifndef STATS_HDR
#define STATS_HDR

#include <iostream>

#include "simple_stats.h"

class Stats : public SimpleStats {
    private:
        double sum2_;
        using super = SimpleStats;
    public:
        Stats() : SimpleStats(), sum2_ {0.0} {};
        void add(double x) { super::add(x); sum2_ += x*x; };
        double sum2() const { return sum2_; };
        double stddev() const;
        friend std::ostream& operator<<(std::ostream&,
                                        const Stats& stats);
};

#endif
