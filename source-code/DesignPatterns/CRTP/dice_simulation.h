#ifndef DICE_SIMULATION_HDR
#define DICE_SIMULATION_HDR

#include <cstdint>
#include <iostream>
#include <random>
#include "simulation.h"


using Throw = int;

struct DiceSimulation : public Simulation<DiceSimulation> {
    protected:
        std::mt19937_64 engine_;
        std::uniform_int_distribution<Throw> distr_ {1, 6};
    public:
        void seed(const std::size_t seed_value) {
            engine_.seed(seed_value);
        }
        void step_implementation() {
            std::cout << distr_(engine_) << '\n';
        };
};

#endif
