#ifndef RULE_HDR
#define RULE_HDR

#include <array>
#include <cstdint>

#include "cells.h"

using Rule = std::array<int8_t, 8>;

Rule create_rule(uint8_t rule_nr);
int neighbourhood_index(const Cells& cells, std::size_t index);

#endif
