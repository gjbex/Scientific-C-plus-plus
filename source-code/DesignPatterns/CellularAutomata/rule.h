#ifndef RULE_HDR
#define RULE_HDR

#include <array>
#include <cstdint>

using Rule = std::array<int8_t, 8>;

Rule create_rule(uint8_t rule_nr);

#endif
