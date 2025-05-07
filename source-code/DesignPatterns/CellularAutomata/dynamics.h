#ifndef DYNAMICS_HDR
#define DYNAMICS_HDR

#include "cells.h"

struct Dynamics {
    public:
        virtual void update(Cells& cells) = 0;
        virtual ~Dynamics() = default;
};

template<typename Dyn>
struct PrintDecorator : public Dyn {
    explicit PrintDecorator(Dyn& dyn) : Dyn(dyn) {}
    void update(Cells& cells) override {
        Dyn::update(cells);
        print_cells(cells);
    }
};

#endif
