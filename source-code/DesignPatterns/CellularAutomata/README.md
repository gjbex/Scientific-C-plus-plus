# Cellular automata

This is a simulation framework for experiments with cellular automata.  It is
mainly intended to illustrate various design principles and design patterns.


## What is it?

1. `cells.h`/`cells.cpp`: definition of the system to simulate and declaration
   of some functions related to such systems.
1. `cells_factory.h`: abstract base class for initializers of the systems.
1. `uniform_cells_factory.h`/`uniform_cells_factory.cpp`: system initializer
   that sets all cells to 1.
1. `random_cells_factory.h`/`random_cells_factory.cpp`: system initializer that
   assigns 0 or 1 to a system randomly.
1. `rule.h`/`rule.cpp`: definition of a rule type for cellular automata.
1. `dynamics.h`: definition of an abstract base class that defines how to
   update a system from one time step to the next.  It also defines a decorator
   that ensures the `update` method writes the system to standard output after
   each call.
1. `cyclic_boundary_dynamics.h`/`cyclic_boundary_dynamics.cpp`: concrete class
   that implements cyclic boundary conditions for the update.
1. `visualization_runner.h`/`visualization_runner.cpp`: defines a runner class
   that runs a system using a given dynamics and writes output that can be used
   to visualize the system's evolution.
1. `cycle_finder.h`/`cycle_finder.cpp`: defines a runner class that runs a
   system using a given dynamics until a cycle is detected.
1. `utils.h`/`utils.cpp`: definition of the utility functions.
1. `main.cpp`: main function definition that drives the simulations.
1. `CMakeLists.txt`: CMake file to build the application.
