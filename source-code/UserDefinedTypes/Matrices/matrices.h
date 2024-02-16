#ifndef MATRICES_HDR
#define MATRICES_HDR

#include <algorithm>
#include <iostream>
#include <memory>
#include <span>

template<typename T>
struct Matrix {
    private:
        int rows_;
        int cols_;
        std::unique_ptr<T[]> data_;
    public:
        Matrix(int rows, int cols) :
            rows_(rows), cols_(cols), data_(new T[rows * cols]) {}
        // copy constructor & assignment operator
        Matrix(const Matrix& other);
        Matrix& operator=(const Matrix& other);
        // move constructor & assignment operator
        Matrix(Matrix&& other) noexcept;
        Matrix& operator=(Matrix&& other) noexcept;
        // matrix indexing by row and column
        T& operator()(int i, int j) { return data_[i * cols_ + j]; }
        T operator()(int i, int j) const { return data_[i * cols_ + j]; }
        // getters for number of rows and columns
        int rows() const { return rows_; }
        int cols() const { return cols_; }
        int size() const { return rows_*cols_; }
        // equality and inequlity operators
        bool operator==(const Matrix& other) const;
        bool operator!=(const Matrix& other) const { return !(*this == other); }
        // accessors for the data using views
        std::span<const T> data() const {
            return std::span<const T>(data_.get(), size());
        }
        std::span<T> data() {
            return std::span<T>(data_.get(), size());;
        }
        // destructor
        ~Matrix() = default;
        // textual representation of the matrix
        template<typename M>
        friend std::ostream& operator<<(std::ostream& os, const Matrix<M>& m);
};

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& other) :
        rows_(other.rows_), cols_(other.cols_),
        data_(new double[rows_ * cols_]) {
    std::copy(other.data_.get(), other.data_.get() + rows_*cols_,
              data_.get());
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
    if (this != &other) {
        rows_ = other.rows_;
        cols_ = other.cols_;
        data_.reset(new double[rows_ * cols_]);
        std::copy(other.data_.get(), other.data_.get() + rows_*cols_,
                 data_.get());
    }
    return *this;
}

template<typename T>
Matrix<T>::Matrix(Matrix<T>&& other) noexcept :
        rows_{other.rows_}, cols_{other.cols_},
        data_{std::move(other.data_)} {
    other.rows_ = 0;
    other.cols_ = 0;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& other) noexcept {
    if (&other != this) {
        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = std::move(other.data_);

        other.rows_ = 0;
        other.cols_ = 0;
    }
    return *this;
}

template<typename T>
bool Matrix<T>::operator==(const Matrix<T>& other) const {
    if (this == &other) {
        return true;
    }
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        return false;
    }
    return std::equal(data().begin(), data().end(), other.data().begin());
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (int i = 0; i < matrix.rows(); ++i) {
        for (int j = 0; j < matrix.cols(); ++j) {
            os << matrix(i, j) << " ";
        }
        os << "\n";
    }
    return os;
};

#endif
