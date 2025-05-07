#ifndef RANDOM_CELLS_FACTORY_HDR
#define RANDOM_CELLS_FACTORY_HDR

#include <algorithm>
#include "cells.h"
#include "cells_factory.h"
#include <random>

struct RandomCellsFactory : public CellsFactory {
    protected:
        std::size_t nr_cells_;
        std::size_t seed_;
        std::mt19937 engine_;
        std::uniform_int_distribution<int8_t> distribution_ {0, 1};
    public:
        explicit RandomCellsFactory(std::size_t nr_cells, std::size_t seed) :
            nr_cells_ {nr_cells}, seed_ {seed}, engine_ {seed} {}
        std::size_t nr_cells() const { return nr_cells_; }
        std::size_t seed() const { return seed_; }
        Cells create() override {
            Cells cells;
            cells.resize(nr_cells_);
            std::generate(cells.begin(), cells.end(), [this]() {
                return distribution_(engine_);
            });
            return cells;
        }
};

#endif
