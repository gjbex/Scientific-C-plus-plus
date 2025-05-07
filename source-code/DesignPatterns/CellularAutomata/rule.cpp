#include "rule.h"


Rule create_rule(uint8_t rule_nr) {
    Rule rule;
    for (std::size_t i = 0; i < rule.size(); ++i) {
        rule[i] = rule_nr % 2;
        rule_nr /= 2;
    }
    return rule;
}
