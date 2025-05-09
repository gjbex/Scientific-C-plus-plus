#include <iostream>
#include <stdexcept>
#include "simple_stats.h"
#include "stats.h"

int main() {
    bool ok = true;

    // Test SimpleStats::mean() with zero data
    try {
        SimpleStats s;
        s.mean();
        std::cerr << "ERROR: SimpleStats::mean() did not throw" << std::endl;
        ok = false;
    } catch (const std::domain_error&) {
    }

    // Test Stats::stddev() with zero data
    try {
        Stats s;
        s.stddev();
        std::cerr << "ERROR: Stats::stddev() did not throw on zero data" << std::endl;
        ok = false;
    } catch (const std::domain_error&) {
    }

    // Test Stats::stddev() with one data point
    try {
        Stats s;
        s.add(1.23);
        s.stddev();
        std::cerr << "ERROR: Stats::stddev() did not throw on one data point" << std::endl;
        ok = false;
    } catch (const std::domain_error&) {
    }

    return ok ? 0 : 1;
}