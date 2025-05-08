#include "random_cells_factory.h"

#include <algorithm>

Cells RandomCellsFactory::create() {
    Cells cells;
    cells.resize(nr_cells_);
    std::generate(cells.begin(), cells.end(), [this]() {
            return distribution_(engine_);
            });
    return cells;
}
