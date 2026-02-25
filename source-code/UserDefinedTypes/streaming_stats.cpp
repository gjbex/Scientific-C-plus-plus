#include <iostream>
#include <vector>

class Stats {

    private:
        double sum_;
        int n_;

    public:
        Stats() : sum_ {0.0}, n_ {0} {};
        int n() const { return n_; };
        double avg() const { return sum_/n_; };
        void add(double data);
};

void Stats::add(double data) {
    sum_ += data;
    n_++;
}

int main() {
    std::vector<double> data {1.2, 2.3, 3.4, 4.5, 5.6};
    Stats stats;
    for (const auto& value: data) {
        stats.add(value);
    }
    std::cout << "average = " << stats.avg() << " for "
              << stats.n() << " data points" << std::endl;
    return 0;
}
