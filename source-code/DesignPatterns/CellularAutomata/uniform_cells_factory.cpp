#include "uniform_cells_factory.h"

#include <algorithm>

Cells UniformCellsFactory::create() {
    Cells cells;
    cells.resize(nr_cells_);
    std::fill(cells.begin(), cells.end(), 1);
    return cells;
}

