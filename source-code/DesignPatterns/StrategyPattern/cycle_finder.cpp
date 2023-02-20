#include "cycle_finder.h"

#include <iostream>

bool CycleFinder::handle(const Automaton& automaton) {
    auto is_automaton_present = [&automaton] (const Automaton& vec_element) {
        return std::equal(std::begin(vec_element), std::end(vec_element),
                          std::begin(automaton));
    };
    auto pos = std::find_if(generations.cbegin(), generations.cend(),
                            is_automaton_present);
    if (pos != generations.cend()) {
        cycle_length_ = generations.cend() - pos;
        return false;
    } else {
        generations.push_back(automaton);
        return true;
    }
}
