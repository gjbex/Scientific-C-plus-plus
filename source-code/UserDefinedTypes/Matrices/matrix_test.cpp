#include <iostream>
#include "matrices.h"

Matrix<double> create_matrix(int rows, int cols) {
    Matrix<double> m(rows, cols);
    for (int i = 0; i < m.rows(); ++i) {
        for (int j = 0; j < m.cols(); ++j) {
            m(i, j) = i * m.cols() + j;
        }
    }
    return m;
}

int main() {
    Matrix<double> m = create_matrix(4, 3);
    std::cout << "m = " << std::endl;
    std::cout << m << std::endl;
    Matrix<double> m2 = m;
    std::cout << "m2 = " << std::endl;
    std::cout << m2 << std::endl;
    Matrix<double> m3(4, 3);
    m3 = m;
    std::cout << "m3 = " << std::endl;
    std::cout << m3 << std::endl;
    return 0;
}
