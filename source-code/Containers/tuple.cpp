#include <iostream>
#include <tuple>

using namespace std;

int main(void) {
    tuple<double, int> electron_prop = make_tuple(9.11e-31, -1);
    cout << "electron mass: " << get<0>(electron_prop) << endl;
    cout << "electron charge: " << get<1>(electron_prop) << endl;
    int charge;
    double mass;
    tie(mass, charge) = electron_prop;
    cout << "electron mass: " << mass << endl;
    cout << "electron charge: " << charge << endl;
    auto pos = std::make_tuple(3.5, 4.3);
    auto [x, y] = pos;
    std::cout << "x = " << x << ", y = " << y << "\n";
    return 0;
}
