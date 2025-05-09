#ifndef INDIVIDUAL_DYNAMICS_HDR
#define INDIVIDUAL_DYNAMICS_HDR

#include <algorithm>

#include "cells.h"
#include "dynamics.h"
#include "rule.h"

struct IndividualDynamics : Dynamics {
    private:
        Rule rule_;
        Cells new_cells_;
        int current_cell_idx_ {0};
    public:
        explicit IndividualDynamics(const Rule& rule, std::size_t nr_cells) : rule_{rule} {
            new_cells_.resize(nr_cells);
        }
        void update(Cells& cells) override;
};

#endif
