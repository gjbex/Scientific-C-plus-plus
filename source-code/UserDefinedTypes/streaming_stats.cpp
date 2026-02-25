#include <iostream>
#include <vector>

class Stats {

    private:
        double _sum;
        int _n;

    public:
        Stats() : _sum {0.0}, _n {0} {};
        int n() const { return _n; };
        double avg() const { return _sum/_n; };
        void add(double data);
};

void Stats::add(double data) {
    _sum += data;
    _n++;
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
