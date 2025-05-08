#include "cyclic_boundary_dynamics.h"

void CyclicBoundaryDynamics::update(Cells& cells) {
    for (std::size_t i = 0; i < cells.size(); ++i) {
        std::size_t index = neighbourhood_index(cells, i);
        new_cells_[i] = rule_[index];
    }
    std::copy(new_cells_.begin(), new_cells_.end(), cells.begin());
}
