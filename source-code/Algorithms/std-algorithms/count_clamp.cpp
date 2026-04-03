#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

int main() {
    const size_t n {10};
    std::mt19937_64 engine;
    auto distr = std::bind(std::uniform_int_distribution<int>(-10, 10), engine);
    std::vector<int> data;
    for (size_t i = 0; i < n; i++)
        data.push_back(distr());
    std::cout << "original sequence:" << std::endl;
    for (const auto& x: data)
        std::cout << x << " ";
    std::cout << std::endl;
    auto nr_pos = count_if(data.cbegin(), data.cend(),
                           [] (int x) { return x > 0; });
    auto nr_neg = count_if(data.cbegin(), data.cend(),
                           [] (int x) { return x < 0; });
    auto nr_zero = count(data.cbegin(), data.cend(), 0);
    std::cout << "negative: " << nr_neg << std::endl;
    std::cout << "zero: " << nr_zero << std::endl;
    std::cout << "positive: " << nr_pos << std::endl;
    std::cout << "total: " << data.size() << std::endl;
    std::cout << "clamp between -5 and 5:" << std::endl;
    const int pos_max {5};
    const int neg_max {-pos_max};
    std::replace_if(data.begin(), data.end(),
            [=] (int x) { return x > pos_max; }, pos_max);
    std::replace_if(data.begin(), data.end(),
            [=] (int x) { return x < neg_max; }, neg_max);
    for (const auto& x: data)
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
