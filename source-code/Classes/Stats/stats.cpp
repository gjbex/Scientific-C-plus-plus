#include <cmath>
#include <stdexcept>

#include "stats.h"

double Stats::stddev() const {
    using std::sqrt;
    if (n() < 2) {
        throw std::domain_error("Stats::stddev(): at least two data points required");
    }
    return sqrt((sum2() - sum()*sum()/n())/(n() - 1));
}

std::ostream& operator<<(std::ostream& out, const Stats& stats) {
    return out << static_cast<SimpleStats>(stats) << std::endl
               << "sum2 = " << stats.sum2();
}
