#include "cycle_finder.h"

void CycleFinder::run(Dynamics& dynamics, Cells& cells) {
    step_ = 0;
    states_.clear();
    while (!has_cycle(cells)) {
        states_[cells_to_key(cells)] = step_;
        dynamics.update(cells);
        step_++;
    }
    cells_ = cells;
}
