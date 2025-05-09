#include "individual_dynamics.h"

void IndividualDynamics::update(Cells& cells) {
    std::size_t index = neighbourhood_index(cells, current_cell_idx_);
    new_cells_[current_cell_idx_] = rule_[index];
    std::copy(new_cells_.begin(), new_cells_.end(), cells.begin());
    current_cell_idx_++;
}
