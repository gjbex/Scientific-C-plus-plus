#include <iostream>
#include "matrix.h"
#include "utils.h"

int main() {
    const int rows {3};
    const int cols {2};
    Matrix m(rows, cols);
    std::cout << m << std::endl;
    m(1, 1) = 12;
    std::cout << m << std::endl;
    fill(m, -13);
    std::cout << m << std::endl;
    return 0;
}
