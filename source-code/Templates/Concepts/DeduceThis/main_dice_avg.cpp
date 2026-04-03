#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include "dice_avg_simulation.h"

int main(int argc, char* argv[]) {
    double threshold {0.1};
    if (argc > 1) {
        try {
            threshold = std::stod(argv[1]);
        } catch (const std::invalid_argument&) {
            std::cerr << "Invalid argument: " << argv[1] << '\n';
            std::exit(1);
        }
    }
    DiceAvgSimulation simulation;
    simulation.seed(1234);
    simulation.seed(1234);
    auto stop_function = [=] (const DiceAvgSimulation& simulation, [[maybe_unused]] const std::size_t step_nr) {
        const auto& distribution {simulation.distribution()};
        double avg {std::accumulate(distribution.begin(), distribution.end(), 0.0)/distribution.size()};
        auto [min, max] = std::ranges::minmax(distribution);
        return (max - min)/avg < threshold;
    };
    simulation.run(stop_function);
    for (const auto& [i, value]: std::ranges::views::enumerate(simulation.distribution())) {
            std::cout << i + 1 << ' ' << value << '\n';
            }
    std::cout << "steps: " << simulation.current_step() << '\n';
    return 0;
}

