#ifndef CYCLE_FINDER_HDR
#define CYCLE_FINDER_HDR

#include <unordered_map>

#include "cells.h"
#include "dynamics.h"
#include "runner.h"

struct CycleResult {
    int cycle_size {0};
    Cells cells;
};

struct CycleFinder : Runner<CycleResult> {
    private:
        std::unordered_map<std::string,int> states_;
        int step_ {};

        bool has_cycle(const Cells& cells) { return states_.find(cells_to_key(cells)) != states_.cend(); }

    public:
        void run(Dynamics& dynamics, Cells& cells) override;
};

#endif
