#ifndef VISUALIZATION_RUNNER_HDR
#define VISUALIZATION_RUNNER_HDR

#include "cells.h"
#include "dynamics.h"

struct VisualizationRunner {
    private:
        int t_max_;
    public:
        explicit VisualizationRunner(int t_max) : t_max_ {t_max} {}
        void run(Dynamics& dynamics, Cells& cells);
};

#endif
