#include "visualization_runner.h"

#include <iostream>

void print_cells(Cells& cells) {
    for (const auto& cell : cells) {
        std::cout << static_cast<int>(cell) << " ";
    }
    std::cout << '\n';
}

void VisualizationRunner::run(Dynamics& dynamics, Cells& cells) {
    print_cells(cells);
    for (int t = 0; t <= t_max_; ++t) {
        dynamics.update(cells);
        print_cells(cells);
    }
}
