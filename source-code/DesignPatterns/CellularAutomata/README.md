# Cellular automata

This is a simulation framework for experiments with cellular
automata.  It is mainly intended to illustrate various design
principles and design patterns.


## What is it?

1. `cells.h`: definition of the system to simulate and
   declaration of some functions related to such systems.
1. `cell.cpp`: definition of the system-related functions.
1. `cells_factory.h`: abstract base class for initializers
   of the systems.
1. `uniform_cells_factory.h`: system initializer that sets
   all cells to 1.
1. `random_cells_factory.h`: system initilizer that assigns
   0 or 1 to a system randomly.
1. `rule.h`: definition of a rule type for cellular automata.
1. `dynamics.h`: definition of an abstract base class that
   defines how to update a system from one time step to the
   next.  It also defines a decorator that ensures the `update`
   method writes the system to standard output after each call.
1. `cyclic_boundary_dynamics.h`: concrete class that implements
   cyclic boundary conditions for the update.
1. `cycle_finder.h`: defines a runner class that runs a system
   using a given dynamics until a cycle is detected.
1. `utils.h`: declaration of untility function, mainly to handle
   command line arguments.
1. `utils.cpp`: definition of the utility functions.
1. `main.cpp`: main function definition that drives the simulations.
1. `CMakeLists.txt`: CMake file to build the application.

