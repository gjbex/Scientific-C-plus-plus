#ifndef CYCLIC_BOUNDARY_DYNAMICS_HDR
#define CYCLIC_BOUNDARY_DYNAMICS_HDR

#include <algorithm>

#include "cells.h"
#include "dynamics.h"
#include "rule.h"

struct CyclicBoundaryDynamics : Dynamics {
    private:
        Rule rule_;
        Cells new_cells_;
    public:
        explicit CyclicBoundaryDynamics(const Rule& rule, std::size_t nr_cells) : rule_{rule} {
            new_cells_.resize(nr_cells);
        }
        void update(Cells& cells) override;
};

#endif
