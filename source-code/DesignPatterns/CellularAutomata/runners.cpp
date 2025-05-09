#include "runners.h"

void execute_runner(RunnerVariant& runner, Dynamics& dynamics, Cells& cells) {
    std::visit([&](auto& r) {
            r.run(dynamics, cells);
    }, runner);
}
