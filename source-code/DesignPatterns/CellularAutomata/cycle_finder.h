#ifndef CYCLE_FINDER_HDR
#define CYCLE_FINDER_HDR

#include <unordered_map>

#include "cells.h"
#include "dynamics.h"

struct CycleFinder {
    private:
        std::unordered_map<Cells,int> states_;
        int step_ {};
        Cells last_state_;

        bool has_cycle(const Cells& cells) { return states_.find(cells) != states_.cend(); }

    public:
        void run(Dynamics& dynamics, Cells& cells) {
            while (!has_cycle(cells)) {
                states_[cells] = step_;
                dynamics.update(cells);
                step_++;
            }
            last_state_ = cells;
        }
        int cycle_size() {
            return step_ - states_[last_state_];
        }
};

#endif
