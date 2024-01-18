#include "array_view.h"
#include <iostream>
#include <vector>

int main() {
    const size_t n = 24;
    std::vector<double> data;
    for (std::size_t i = 0; i < n; ++i) {
        data.push_back(i);
    }
    ArrayView<double, 6, 4> view2(data.data());
    std::cout << "view2(" << view2.shape(0) << ", " << view2.shape(1) << "):\n";
    for (std::size_t i = 0; i < view2.shape(0); ++i) {
        for (std::size_t j = 0; j < view2.shape(1); ++j) {
            std::cout << view2(i, j) << " ";
        }
        std::cout << "\n";
    }
    ArrayView<double, 2, 3, 4> view3(data.data());
    std::cout << "\n\n" << "view3(" << view3.shape(0) << ", " << view3.shape(1) << ", " << view3.shape(2) << "):\n";
    for (std::size_t i = 0; i < view3.shape(0); ++i) {
        for (std::size_t j = 0; j < view3.shape(1); ++j) {
            for (std::size_t k = 0; k < view3.shape(2); ++k) {
                std::cout << view3(i, j, k) << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    /*
     * This will not compile thanks to the static_asserts in the operator() functions
    std::cout << "view3(1, 2) = " << view3(1, 2) << "\n";
    */
    return 0;
}
