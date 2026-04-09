#include <iostream>
#include <mdspan>
#include <vector>

int main() {
    std::vector<double> data {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
    // auto span = std::experimental::mdspan<double, std::experimental::extents<10, 10>>(data.data(), 10, 10);
    auto span2d = std::mdspan<double, std::experimental::extents<10, 10>>(data.data(), 2, 6);
    for (int i = 0; i < span2d.extent(0); ++i) {
        for (int j = 0; j < span2d.extent(1); ++j) {
            std::cout << span2d(i, j) << " ";
        }
        std::cout << std::endl;
    }
    auto span3d = std::mdspan<double, std::experimental::extents<10, 10>>(data.data(), 2, 2, 3);
    for (int i = 0; i < span3d.extent(0); ++i) {
        for (int j = 0; j < span3d.extent(1); ++j) {
            for (int k = 0; k < span3d.extent(2); ++k) {
                std::cout << span3d(i, j, k) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
