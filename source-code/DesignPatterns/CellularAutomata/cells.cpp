#include "cells.h"

void print_cells(const Cells& cells) {
    for (const auto cell : cells) {
        std::cout << static_cast<int>(cell) << " ";
    }
    std::cout << '\n';
}
