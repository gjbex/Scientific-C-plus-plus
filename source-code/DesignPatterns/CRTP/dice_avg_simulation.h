#ifndef DICE_AVG_SIMULATION_HDR
#define DICE_AVG_SIMULATION_HDR

#include <array>
#include <cstdint>
#include <iostream>
#include <random>
#include "simulation.h"


using Throw = int;
using Distribution = std::array<std::size_t, 6>;

struct DiceAvgSimulation : public Simulation<DiceAvgSimulation> {
    protected:
        std::mt19937_64 engine_;
        std::uniform_int_distribution<Throw> distr_ {1, 6};
        Distribution throw_distr_ = {0};
    public:
        void seed(const std::size_t seed_value) {
            engine_.seed(seed_value);
        }
        void step_implementation() {
            throw_distr_[distr_(engine_) - 1]++;
        };
        const Distribution& distribution() const {
            return throw_distr_;
        }
};

#endif
