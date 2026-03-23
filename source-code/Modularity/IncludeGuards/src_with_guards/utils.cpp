#include "utils.h"

void fill(Matrix& m, const int value) {
    for (int i = 0; i < m.rows(); ++i) {
        for (int j = 0; j < m.cols(); ++j) {
            m(i, j) = value;
        }
    }
}
