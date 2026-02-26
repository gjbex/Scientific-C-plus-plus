#include <functional>
#include <iostream>
#include <limits>
#include <random>

using seed_dist_t = std::uniform_int_distribution<std::size_t>;

int main() {
    std::random_device dev;
    seed_dist_t seed_distr(0, std::numeric_limits<std::size_t>::max());
    auto seed = seed_distr(dev);
    std::cout << seed << std::endl;
    std::mt19937_64 engine(seed);
    auto die_distr = std::bind(std::uniform_int_distribution<int>(1, 6), engine);
    for (int i = 0; i < 5; i++)
        std::cout << die_distr() << std::endl;
    return 0;
}
