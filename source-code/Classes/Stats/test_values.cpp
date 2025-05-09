#include <cmath>
#include <iostream>
#include <vector>
#include <stdexcept>
#include "simple_stats.h"
#include "stats.h"

int main() {
    std::vector<double> data {1.0, 2.0, 3.0, 4.0, 5.0};
    SimpleStats s;
    Stats st;
    for (double x : data) {
        s.add(x);
        st.add(x);
    }
    const double expected_mean = 3.0;
    const double expected_stddev = std::sqrt(2.5); // sqrt(sum((xi-mean)^2)/(n-1))
    bool ok = true;
    double mean_s = 0.0, mean_st = 0.0, stddev = 0.0;
    try {
        mean_s = s.mean();
    } catch (const std::exception& e) {
        std::cerr << "SimpleStats::mean() threw unexpectedly: " << e.what() << std::endl;
        return 1;
    }
    try {
        mean_st = st.mean();
    } catch (const std::exception& e) {
        std::cerr << "Stats::mean() threw unexpectedly: " << e.what() << std::endl;
        return 1;
    }
    try {
        stddev = st.stddev();
    } catch (const std::exception& e) {
        std::cerr << "Stats::stddev() threw unexpectedly: " << e.what() << std::endl;
        return 1;
    }
    if (std::fabs(mean_s - expected_mean) > 1e-9) {
        std::cerr << "SimpleStats mean mismatch: got " << mean_s << " expected " << expected_mean << std::endl;
        ok = false;
    }
    if (std::fabs(mean_st - expected_mean) > 1e-9) {
        std::cerr << "Stats mean mismatch: got " << mean_st << " expected " << expected_mean << std::endl;
        ok = false;
    }
    if (std::fabs(stddev - expected_stddev) > 1e-9) {
        std::cerr << "Stats stddev mismatch: got " << stddev << " expected " << expected_stddev << std::endl;
        ok = false;
    }
    return ok ? 0 : 1;
}