#include <iostream>
#include "dice_simulation.h"

int main() {
    DiceSimulation simulation;
    simulation.seed(1234);
    simulation.run(10);
    std::cout << "----------------\n";
    simulation.seed(1234);
    StopFunction<DiceSimulation> stop_function = [] ([[maybe_unused]] const DiceSimulation& sim, const std::size_t step_nr) {
        return step_nr > 9;
    };
    simulation.run(stop_function);
    return 0;
}
