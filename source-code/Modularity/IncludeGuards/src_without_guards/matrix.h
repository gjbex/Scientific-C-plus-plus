#include <iostream>
#include  <vector>

struct Matrix {
    private:
        std::vector<int> elements_;
        int rows_;
        int cols_;
    public:
        Matrix(int rows, int cols) : elements_(rows*cols, 0), rows_ {rows}, cols_ {cols} {}
        int rows() const { return rows_; }
        int cols() const { return cols_; }
        int& operator()(const int i, const int j) { return elements_[j + i*cols_]; }
        const int& operator()(const int i, const int j) const { return elements_[j + i*cols_]; }
};

std::ostream& operator<<(std::ostream& out, const Matrix& m);
