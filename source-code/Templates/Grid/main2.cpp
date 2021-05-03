#include <iostream>
#include "grid.h"

int main() {
    Grid<double> grid(3, 4);
    for (size_t row = 0; row < grid.nr_rows(); ++row) {
        for (size_t col = 0; col < grid.nr_cols(); ++col) {
            grid(row, col) = 3.12;
        }
    }
    grid(1, 2) = -5.2;
    std::cout << grid;
    return 0;
}
