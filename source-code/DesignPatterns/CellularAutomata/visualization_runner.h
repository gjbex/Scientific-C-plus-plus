#ifndef VISUALIZATION_RUNNER_HDR
#define VISUALIZATION_RUNNER_HDR

#include "runner.h"

struct VisualizationRunner : Runner<Cells> {
    private:
        int t_max_;
        Cells cells_;
    public:
        explicit VisualizationRunner(int t_max) : t_max_ {t_max} {}
        void run(Dynamics& dynamics, Cells& cells) override;
};

#endif
