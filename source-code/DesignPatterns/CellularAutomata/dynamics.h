#ifndef DYNAMICS_HDR
#define DYNAMICS_HDR

#include "cells.h"
#include <memory>
#include <utility>

struct Dynamics {
    public:
        virtual void update(Cells& cells) = 0;
        virtual ~Dynamics() = default;
};

struct PrintDecorator : public Dynamics {
    private:
        std::unique_ptr<Dynamics> inner_;
    
    public:
        explicit PrintDecorator(std::unique_ptr<Dynamics> inner)
            : inner_(std::move(inner)) {}

        void update(Cells& cells) override {
            inner_->update(cells);
            print_cells(cells);
        }

};

#endif
