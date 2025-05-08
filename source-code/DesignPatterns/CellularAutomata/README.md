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


## Design principles and patterns

1. Factory Method / Simple Factory
   • CellsFactory + `create_cells_factory(...)` → Uniform vs. Random initializers
   • `create_runner(...)` → VisualizationRunner vs. CycleFinder
   Encapsulates object‐creation logic behind a common interface.
2. Strategy Pattern
   • `struct Dynamics { virtual void update(...) = 0; }`
   • Concrete strategies: `CyclicBoundaryDynamics` (and wrapped by `PrintDecorator`)
   Encapsulates the evolving‐state algorithm so you can swap it in/out at runtime.
3. Decorator Pattern
   • `PrintDecorator` wraps any `Dynamics` implementation to add logging without modifying it
   Demonstrates “extend behavior by composition” rather than inheritance.
4. Variant + Visitor (a type-safe union)
   • `using RunnerVariant = std::variant<CycleFinder, VisualizationRunner>;`
   • `std::visit(...)` to dispatch `run()` and then handle the `CycleFinder` case
   Avoids a common base‐class for runners and still gives you dynamic dispatch.
5. Single Responsibility Principle (SRP)
   • `utils.cpp` only parses flags,
   • factories only build cell containers,
   • dynamics only update state,
   • runners only drive the simulation and collect results.
6. Open/Closed Principle (OCP)
   You can add new initializers, dynamics, or runners by
   • defining a new `CellsFactory` subclass or `Dynamics` subclass,
   • extending the factory function (or the `std::variant`)—without touching the core loop.
7. Dependency Inversion Principle (DIP)
   High‐level code in `main()` depends on the abstractions (`CellsFactory`, `Dynamics`), not on concrete types.
8. Liskov Substitution Principle (LSP)
   Any `Dynamics` implementation (or decorated variant) can be substituted for the base `Dynamics&` in the runner.
9. RAII & Smart Pointers
   `std::unique_ptr` everywhere for automatic lifetime management and exception safety.
10. Separation of Concerns
       Clear modular division: argument parsing, object creation, simulation logic, and I/O/output are all in separate components.
