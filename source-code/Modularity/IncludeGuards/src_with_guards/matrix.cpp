#include "matrix.h"

std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    for (int i = 0; i < m.rows(); ++i) {
        for (int j = 0; j < m.cols(); ++j) {
            out << m(i, j) << ' ';
        }
        out << '\n';
    }
    return out;
}
