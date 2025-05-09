#include <sstream>

#include "cells.h"

void print_cells(const Cells& cells) {
    for (const auto cell : cells) {
        if (cell == 1) {
            std::cout << "X";
        } else {
            std::cout << " ";
        }
    }
    std::cout << '\n';
}

std::string cells_to_key(const Cells& cells) {
    std::ostringstream oss;
    for (const auto& cell : cells) {
        oss << cell;
    }
    return oss.str();
}
