#ifndef RUNNER_HDR
#define RUNNER_HDR

#include "cells.h"
#include "dynamics.h"

template<typename R>
struct Runner {
    protected:
        R result_ {};
    public:
        virtual void run(Dynamics& dynamics, Cells& cells) = 0;
        const R result() const { return result_; }
        virtual ~Runner() = default;
};

#endif
