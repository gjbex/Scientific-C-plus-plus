#include <iostream>
#include <tuple>

int main(void) {
    // tuples can be constructed with `std::make_tuple`
    std::tuple<double, int> electron_prop = std::make_tuple(9.11e-31, -1);

    // accessing tuple elements with `std::get`
    std::cout << "electron mass: " << std::get<0>(electron_prop) << std::endl;
    std::cout << "electron charge: " << std::get<1>(electron_prop) << std::endl;

    // modifying tuple elements with `std::get`
    std::get<0>(electron_prop) = 9.10938356e-31; // more precise value for electron mass
    std::cout << "updated electron mass:" << std::get<0>(electron_prop) << std::endl;
    std::cout << "electron charge: " << std::get<1>(electron_prop) << std::endl;

    // unpacking tuple elements with `std::tie`
    int charge;
    double mass;
    std::tie(mass, charge) = electron_prop;
    std::cout << "electron mass: " << mass << std::endl;
    std::cout << "electron charge: " << charge << std::endl;

    // unpacking tuple elements with structured bindings (C++17)
    auto pos = std::make_tuple(3.5, 4.3);
    auto [x, y] = pos;
    std::cout << "x = " << x << ", y = " << y << std::endl;

    return 0;
}
