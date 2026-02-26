#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>


struct Stats {
    double mean, stddev, median;
    int n;
};

std::vector<double> read_data(std::istream& in);
Stats compute_stats(std::vector<double> data);

int main() {
    auto data {read_data(std::cin)};
    auto stats {compute_stats(data)};
    std::cout << "mean = " << stats.mean << std::endl;
    std::cout << "std.dev. = " << stats.stddev << std::endl;
    std::cout << "median = " << stats.median << std::endl;
    std::cout << "n = " << stats.n << std::endl;
    return 0;
}

std::vector<double> read_data(std::istream& in) {
    std::vector<double> data;
    double item;
    while (in >> item)
        data.push_back(item);
    return data;
}

Stats compute_stats(std::vector<double> data) {
    int n = data.size();
    double sum {0.0};
    double sum2 {0.0};
    for (double item: data) {
        sum += item;
        sum2 += item*item;
    }
    Stats stats;
    stats.mean = sum/n;
    stats.stddev = std::sqrt(sum2/n - stats.mean*stats.mean);
    std::sort(data.begin(), data.end());
    int middle {n/2};
    stats.median = n % 2 == 1 ? data.at(middle) :
        (data.at(middle - 1) + data.at(middle))/2.0;
    stats.n = n;
    return stats;
}
