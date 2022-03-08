#include <iostream>
#include "grid.h"

int main() {
    Grid<int> grid(-2, 3, 2, 5);
    for (long row = grid.row_min(); row <= grid.row_max(); ++row) {
        for (long col = grid.col_min(); col <= grid.col_max(); ++col) {
            grid(row, col) = 3;
        }
    }
    grid(-1, 4) = 1;
    std::cout << grid;
    return 0;
}
