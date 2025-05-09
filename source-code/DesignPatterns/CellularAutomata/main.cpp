#include <iostream>

#include "utils.h"

int main(int argc, char* argv[]) {
    auto options = parse_arguments(argc, argv);
    auto factory = create_cells_factory(options);
    auto cells = factory->create();
    auto dynamics = create_dynamics(options);
    auto runner = create_runner(options);
    execute_runner(runner, *dynamics, cells);
    handle_runner_result(runner, options);
    return 0;
}
