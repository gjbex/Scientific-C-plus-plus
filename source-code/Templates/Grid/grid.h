#ifndef GRID_HDR
#define GRID_HDR

#include <iostream>
#include <valarray>

template<typename T>
class Grid {
    private:
        long row_min_, row_max_, col_min_, col_max_;
        size_t nr_rows_, nr_cols_;
        std::valarray<T> values_;
    public:
        Grid(long row_min, long row_max, long col_min, long col_max) :
            row_min_ {row_min}, row_max_ {row_max},
            col_min_ {col_min}, col_max_ {col_max},
            nr_rows_ {static_cast<size_t>(row_max - row_min + 1)},
            nr_cols_ {static_cast<size_t>(col_max - col_min + 1)},
            values_(nr_rows_*nr_cols_)
        {}
        Grid(size_t nr_rows, size_t nr_cols) : Grid(0, nr_rows - 1, 0, nr_cols - 1) {}
        long row_min() const { return row_min_; }
        long row_max() const { return row_max_; }
        long col_min() const { return col_min_; }
        long col_max() const { return col_max_; }
        size_t nr_rows() const { return nr_rows_; }
        size_t nr_cols() const { return nr_cols_; }
        T& operator()(long row, long col) {
            return values_[(row - row_min_)*nr_cols_ + (col - col_min_)];
        }
        template<typename GridT>
        friend std::ostream& operator<<(std::ostream& out, const Grid<GridT>& grid);
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Grid<T>& grid) {
    for (size_t row = 0; row < grid.nr_rows(); ++row) {
        for (size_t col = 0; col < grid.nr_cols(); ++col) {
            out << grid.values_[row*grid.nr_cols_ + col] << " ";
        }
        out << "\n";
    }
    return out;
}

#endif
