#include <iostream>
#include <type_traits>

#include "utils.h"

int main(int argc, char* argv[]) {
    auto options = parse_arguments(argc, argv);
    auto factory = create_cells_factory(options);
    auto cells = factory->create();
    auto dynamics = create_dynamics(options);
    auto runner = create_runner(options);
    std::visit([&](auto& r) {
        r.run(*dynamics, cells);
    }, runner);
    std::visit([](auto& r) {
        using RunnerT = std::decay_t<decltype(r)>;
        if constexpr (std::is_same_v<RunnerT, CycleFinder>) {
            std::cout << "Cycle size: " << r.cycle_size() << std::endl;
        }
    }, runner);
    return 0;
}
