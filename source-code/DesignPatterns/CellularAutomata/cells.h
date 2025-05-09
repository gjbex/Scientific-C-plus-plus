#ifndef CELLS_HDR
#define CELLS_HDR

#include <cstdint>
#include <iostream>
#include <vector>

using Cells = std::vector<int8_t>;

void print_cells(const Cells& cells);
std::string cells_to_key(const Cells& cells);

#endif
