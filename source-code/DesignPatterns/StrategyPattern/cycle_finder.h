#ifndef CYCLE_FINDER_HDR
#define CYCLE_FINDER_HDR

#include <vector>
#include "automaton_runner.h"

using Generations = std::vector<Automaton>;

class CycleFinder: public GenerationHandler {
    private:
        Generations generations;
        size_t cycle_length_ {0};
    public:
        bool handle(const Automaton& automaton) override;
        size_t cycle_length() const { return cycle_length_; }
        ~CycleFinder() override = default;
};

#endif
