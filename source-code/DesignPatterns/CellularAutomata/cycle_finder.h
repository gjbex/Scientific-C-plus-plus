#ifndef CYCLE_FINDER_HDR
#define CYCLE_FINDER_HDR

#include <unordered_map>

#include "cells.h"
#include "dynamics.h"

struct CycleFinder {
    private:
        std::unordered_map<std::string,int> states_;
        int step_ {};
        Cells cells_;

        bool has_cycle(const Cells& cells) { return states_.find(cells_to_key(cells)) != states_.cend(); }

    public:
        void run(Dynamics& dynamics, Cells& cells);
        int cycle_size() const { return step_ - states_.at(cells_to_key(cells_)); }
};

#endif
