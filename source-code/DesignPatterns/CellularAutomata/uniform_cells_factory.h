#ifndef UNIFORM_CELLS_FACTORY_HDR
#define UNIFORM_CELLS_FACTORY_HDR

#include "cells.h"
#include "cells_factory.h"

struct UniformCellsFactory : public CellsFactory {
    private:
        std::size_t nr_cells_;
    public:
        explicit UniformCellsFactory(std::size_t nr_cells) : nr_cells_ {nr_cells} {}
        std::size_t nr_cells() const { return nr_cells_; }
        Cells create() override;
};

#endif
