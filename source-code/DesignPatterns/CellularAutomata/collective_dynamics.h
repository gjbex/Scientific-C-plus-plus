#ifndef COLLECTIVE_DYNAMICS_HDR
#define COLLECTIVE_DYNAMICS_HDR

#include <algorithm>

#include "cells.h"
#include "dynamics.h"
#include "rule.h"

struct CollectiveDynamics : Dynamics {
    private:
        Rule rule_;
        Cells new_cells_;
    public:
        explicit CollectiveDynamics(const Rule& rule, std::size_t nr_cells) : rule_{rule} {
            new_cells_.resize(nr_cells);
        }
        void update(Cells& cells) override;
};

#endif
