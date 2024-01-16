#include <algorithm>
#include "matrices.h"

Matrix::Matrix(const Matrix& other) :
        rows_(other.rows_), cols_(other.cols_),
        data_(new double[rows_ * cols_]) {
    std::copy(other.data_.get(), other.data_.get() + rows_*cols_,
              data_.get());
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        rows_ = other.rows_;
        cols_ = other.cols_;
        data_.reset(new double[rows_ * cols_]);
        std::copy(other.data_.get(), other.data_.get() + rows_*cols_,
                 data_.get());
    }
    return *this;
}
Matrix::Matrix(Matrix&& other) noexcept :
        rows_{other.rows_}, cols_{other.cols_},
        data_{std::move(other.data_)} {
    other.rows_ = 0;
    other.cols_ = 0;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept {
    if (&other != this) {
        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = std::move(other.data_);

        other.rows_ = 0;
        other.cols_ = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows_; ++i) {
        for (int j = 0; j < m.cols_; ++j) {
            os << m(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}
