#include "automaton_runner.h"

AutomatonRunner::AutomatonRunner(uint8_t rule_nr) {
    for (uint8_t i = 0; i < rules.size(); ++i) {
        rules[i] = rule_nr % 2;
        rule_nr /= 2;
    }
}

Automaton AutomatonRunner::next_generation(const Automaton& automaton) {
    uint8_t idx;
    size_t nr_cells {automaton.size()};
    Automaton ng_automaton(nr_cells);
    // first cell
    idx = automaton[nr_cells - 1] << 2 | automaton[0] << 1 | automaton[1];
    ng_automaton[0] = rules[idx];
    // second to one before last cell
    for (size_t cell_nr = 1; cell_nr < nr_cells - 1; ++cell_nr) {
        idx = automaton[cell_nr - 1] << 2 | automaton[cell_nr] << 1 | automaton[cell_nr + 1];
        ng_automaton[cell_nr] = rules[idx];
    }
    // last cell
    idx = automaton[nr_cells - 2] << 2 | automaton[nr_cells - 1] << 1 | automaton[0];
    ng_automaton[nr_cells - 1] = rules[idx];
    return ng_automaton;
}

void AutomatonRunner::evolve(Automaton& automaton, const size_t nr_generations,
                             GenerationHandler* handler) {
    if (!handler->handle(automaton)) return;
    for (size_t gen_nr = 0; gen_nr < nr_generations; ++gen_nr) {
        automaton  = next_generation(automaton);
        if (!handler->handle(automaton)) return;
    }
}
