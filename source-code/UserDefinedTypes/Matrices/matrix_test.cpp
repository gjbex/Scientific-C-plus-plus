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
    auto m4 = create_matrix(4, 3);
    if (m4 == m3) {
        std::cout << "matrices equal\n";
    }
    m4(0, 0) = -29.0;
    if (m4 != m3) {
        std::cout << "matrices unequal\n";
    }
    std::fill(m4.data().begin(), m4.data().end(), 1.0);
    std::cout << m4 << std::endl;
    return 0;
}
