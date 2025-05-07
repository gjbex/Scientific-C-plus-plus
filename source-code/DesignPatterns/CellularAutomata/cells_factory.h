#ifndef CELLS_FACTORY_HDR
#define CELLS_FACTORY_HDR

#include "cells.h"

struct CellsFactory {
    public:
        virtual Cells create() = 0;
        virtual ~CellsFactory() = default;
};

#endif
