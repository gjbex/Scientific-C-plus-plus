#include <functional>
#include <iostream>
#include <random>


int main() {
    std::mt19937_64 engine_1(1234);
    auto x_distr_1 = std::bind(std::uniform_int_distribution<int>(0, 5), engine_1);
    auto y_distr_1 = std::bind(std::uniform_int_distribution<int>(0, 5), engine_1);
    std::cout << "no ref. wrapper" << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << x_distr_1() << " " << y_distr_1() << std::endl;
    std::mt19937_64 engine_2(1234);
    auto x_distr_2 = std::bind(std::uniform_int_distribution<int>(0, 5),
                          std::ref(engine_2));
    auto y_distr_2 = std::bind(std::uniform_int_distribution<int>(0, 5),
                          std::ref(engine_2));
    std::cout << "ref. wrapper" << std::endl;
    for (int i = 0; i < 3; i++)
        std::cout << x_distr_2() << " " << y_distr_2()<< std::endl;
    return 0;
}
