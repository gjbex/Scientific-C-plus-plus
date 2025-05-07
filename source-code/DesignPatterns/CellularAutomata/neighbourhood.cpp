#include "neighbourhood.h"

int neighbourhood_index(const Cells& cells, std::size_t index) {
    int8_t left_neighbour_value = index > 0 ? cells[index - 1] : cells[cells.size() - 1];
    int8_t right_neighbour_value = index < cells.size() - 1 ? cells[index + 1] : cells[0];
    return 4*left_neighbour_value + 2*cells[index] + right_neighbour_value;
}
