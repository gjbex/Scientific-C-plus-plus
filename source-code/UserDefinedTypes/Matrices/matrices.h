#ifndef MATRICES_HDR
#define MATRICES_HDR

#include <iostream>
#include <memory>


struct Matrix {
    private:
        int rows_;
        int cols_;
        std::unique_ptr<double[]> data_;
    public:
        Matrix(int rows, int cols) :
            rows_(rows), cols_(cols), data_(new double[rows * cols]) {}
        // copy constructor & assignment operator
        Matrix(const Matrix& other);
        Matrix& operator=(const Matrix& other);
        // move constructor & assignment operator
        Matrix(Matrix&& other) noexcept;
        Matrix& operator=(Matrix&& other) noexcept;
        // matrix indexing by row and column
        double& operator()(int i, int j) { return data_[i * cols_ + j]; }
        double operator()(int i, int j) const { return data_[i * cols_ + j]; }
        // getters for number of rows and columns
        int rows() const { return rows_; }
        int cols() const { return cols_; }
        // accessors for the data
        double* data() { return data_.get(); }
        const double* data() const { return data_.get(); }
        // destructor
        ~Matrix() = default;
        // textual representation of the matrix
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};

#endif
