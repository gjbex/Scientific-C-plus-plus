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
1. `collective_dynamics.h`/`collective_dynamics.cpp`: concrete class
   that implements a collective update for the system.
1. `runners.h`/`runners.cpp`: definition of relevant types and some utility functions.
1. `visualization_runner.h`/`visualization_runner.cpp`: defines a runner class
   that runs a system using a given dynamics and writes output that can be used
   to visualize the system's evolution.
1. `cycle_finder.h`/`cycle_finder.cpp`: defines a runner class that runs a
   system using a given dynamics until a cycle is detected.
1. `utils.h`/`utils.cpp`: definition of the utility functions.
1. `main.cpp`: main function definition that drives the simulations.
1. `CMakeLists.txt`: CMake file to build the application.
1. `add-dynamics`: directory containing a new dynamics to be added to the
   simulation.


## Extension

By way of example, the directory `add-dynamics` contains all the files that need
to be added or modified to add a new dynamics to the simulation.


## Design principles: SOLID

This code tries to illustrate the SOLID principles of object-oriented design.


### Single responsibility principle (SRP)

There are lots of little classes in this codebase that each do exactly one
thing—classic Single Responsibility Principle in action. A few of the clearest
examples:

* `RandomCellsFactory` / `UniformCellsFactory` – Each subclass is solely
  responsible for one way of initializing the cell array: “random” vs.
  “uniform.” They don’t also try to parse CLI flags, drive the simulation, or
  print output.
* `CollectiveDynamics` – Knows only how to take one time‐step of the
  automaton under collective updates.  It doesn’t manage I/O, cycle detection,
  or any higher‐level orchestration.
* `PrintDecorator` – Wraps any Dynamics to add exactly one bit of extra
  behavior—printing the cell state after each update.  Nothing more.
* `CycleFinder` – Runs the automaton until it sees a repeated state, then
  exposes only the cycle length.  It doesn’t do visualization, metric
  logging, or argument parsing.
* `VisualizationRunner` – Knows only how to step through and print each
  generation up to a fixed t_max.  It doesn’t detect cycles or compute any
  statistics.
* `parse_arguments()`/`create_cells_factory()`/`create_dynamics()`/`create_runner()`
  – Each free function groups together one piece of setup logic: CLI parsing,
  factory construction, dynamics construction, runner construction.  None of
  them overlap.

By keeping each of those types or functions laser-focused on exactly one aspect
of the program, you avoid “God classes” and make each unit easy to understand,
test, and maintain.


### Open/closed principle (OCP)

A number of places in this code base are designed so that you can add new
behavior (new cell‐initializers, new dynamics, new runners, new “print”
policies, etc.) without ever touching the code that uses them.  That is exactly
the Open–Closed Principle (“open for extension, closed for modification”).
Here are the clearest examples:

1. Abstract Interfaces + Factory Functions
   – In `cells_factory.h` you have
     ```cpp
       struct CellsFactory {
         virtual Cells create() = 0;
         virtual ~CellsFactory() = default;
       };
     ```
     The free function `create_cells_factory(...)` returns a
     `unique_ptr<CellsFactory>`.  Adding any new initializer (say, a
     “checkerboard” initializer) means writing a new subclass of `CellsFactory`
     and extending only `create_cells_factory()`.  None of your simulation or
     `main()` code has to change.
   – Similarly in `dynamics.h` you have
     ```cpp
       struct Dynamics {
         virtual void update(Cells& cells) = 0;
         virtual ~Dynamics() = default;
       };
    ```
    The factory `create_dynamics(...)` returns a `unique_ptr<Dynamics>`.  To
    support a new boundary condition or rule, you simply write another
    `Dynamics` subclass and hook it up in `create_dynamics()`.  The rest of the
    code still just calls `d->update(cells);`—no modification needed there.
1. Decorator Pattern for “verbose” output
   – Instead of sprinkling `if (verbose)` checks throughout every `Dynamics`
     implementation, we have
     ```cpp
       struct PrintDecorator : public Dynamics {
         explicit PrintDecorator(unique_ptr<Dynamics> inner);
         void update(Cells& c) override {
           inner_->update(c);
           print_cells(c);
         }
       };
     ```
     If later you want another kind of logging or tracing, you can write a new
     decorator class wrapping `Dynamics`—without ever touching
     `CollectiveDynamics` itself.
1. Runner Variant + `std::visit` Dispatch
   – We model “what to do with the simulation” as a
     `using RunnerVariant = std::variant<CycleFinder`, VisualizationRunner>;`
   – The `main()` (or your new `execute_runner()`) simply does a `std::visit(...)`
     and calls `run()`.  Adding a third runner (e.g. a “statistics collector”)
     means creating a new `struct StatsRunner { … run(...) … };` and adding it to
     the variant plus to `create_runner()`.  Nowhere in the core simulation loop do
     you have to rewrite the stepping logic.

In all of these cases the clients (main loop, other utility code) stay
completely untouched when you add new behaviors.  You only ever add new classes
or new branches in your factory/variant builder, so the rest of the system is
“closed” against modification.


### Liskov substitution principle (LSP)

Anyplace you have an abstract base (or interface) and concrete subclasses that
can be swapped in without changing client code is an LSP example. Two of the
clearest spots are:

1. The `Dynamics` hierarchy
    * In `dynamics.h` you have
      ```cpp
      struct Dynamics {
          virtual void update(Cells& cells) = 0;
          virtual ~Dynamics() = default;
      };
      ```
    * `CollectiveDynamics` implements the core automaton step, and
      `PrintDecorator` publicly inherits from Dynamics, wrapping another Dynamics.
    * Because `PrintDecorator::update(…)` still satisfies the exact same “take one
      time-step” contract (it just adds a print afterward), any code that does
      ```cpp
      void simulate(Dynamics& dyn, Cells& cells) {
          dyn.update(cells);
      }
      ```
      will work *identically* whether `dyn` is a plain `CollectiveDynamics`
      or a `PrintDecorator`.  That is classic Liskov substitution.
2. The `CellsFactory` interface
    * In `cells_factory.h`:
      ```cpp
      struct CellsFactory {
          virtual Cells create() = 0;
          virtual ~CellsFactory() = default;
      };
      ```
    * Both `UniformCellsFactory` and `RandomCellsFactory` override `create()`
      to produce a valid `Cells` vector.  Client code only ever holds
      `std::unique_ptr<CellsFactory>` and calls `factory->create()`.  You can
      freely swap in the random or uniform factory without touching any of the
      calling code.

In both cases the subclasses preserve the base‐class contract (no stronger
preconditions, same or weaker postconditions) so that clients written against
the abstract type continue to work correctly—exactly what LSP demands.


### Interface segregation principle (ISP)

This codebase is full of small, focused interfaces that illustrate ISP in
action. A few concrete examples:

* `CellsFactory` (`cells_factory.h`)
  – Interface:
    ```cpp
    struct CellsFactory {
        virtual Cells create() = 0;
        virtual ~CellsFactory() = default;
    };
    ```
  – Implementations (`UniformCellsFactory`, `RandomCellsFactory`) only have to
    provide a single `create()` method.  No client ever has to depend on, or even
    see, a fat factory interface with methods it doesn’t use.
* `Dynamics` (`dynamics.h`)
  – Interface:
    ```cpp
    struct Dynamics {
        virtual void update(Cells& cells) = 0;
        virtual ~Dynamics() = default;
    };
    ```
  – Concrete classes (`CollectiveDynamics`) and the `PrintDecorator` only
    implement `update()`.  Nothing more is shoe-horned in.
* Runner types via `std::variant` (`utils.h`)
  – Instead of one big “Runner” interface with a bunch of optional hooks, we
    have two completely separate types—`CycleFinder` and `VisualizationRunner`—each
    of which only needs to implement a single `run(Dynamics&, Cells&)` method.
    Clients drive them polymorphically via a std::variant, so neither runner is
    forced to carry unused methods.

By keeping each interface down to a single, well-defined operation, every
implementation only sees exactly what it needs—and nothing more. That’s the
essence of the Interface Segregation Principle.


### Dependency inversion principle (DIP)

This project uses Dependency Inversion in several places. The clearest one is
how your high‐level “orchestration” code depends only on abstract interfaces,
and the low‐level concrete types depend on those abstractions:

* In `main.cpp` you never #include "`uniform_cells_factory.h`" or new
  `CollectiveDynamics` yourself—you only include `utils.h` and work with:
  – `std::unique_ptr<CellsFactory>`
  – `std::unique_ptr<Dynamics>`
  – `RunnerVariant` (the `std::variant` of runners)
  The functions `create_cells_factory(...)`, - `create_dynamics(...)`, and
  `create_runner(...)` decide which concrete classes to instantiate.
  High-level module (main) → depends on → abstractions (`CellsFactory`, `Dynamics`,
  `RunnerVariant`).
* The concrete factories (`RandomCellsFactory`, `UniformCellsFactory`), dynamics
  (`CollectiveDynamics`) and runners (`VisualizationRunner`, `CycleFinder`) all
  inherit from those abstract interfaces.
  Low-level modules (those concrete classes) → depend on → the abstract interfaces.

Because of this inversion:

1. The high-level logic is closed against changes in the low-level details—you
   can add a brand-new `CellsFactory` or `Dynamics` implementation without touching
   `main.cpp`.
2. Abstractions live “up” in `utils.h`, and all the implementation details
   “down” in their `.cpp`/`.h` files just implement those interfaces.

That separation of “I only code to the interface” (high -> abstract) and “I
implement that interface” (low -> abstract) is classic Dependency Inversion.


## General Design patterns

1. Factory Method / Simple Factory: encapsulates object‐creation logic behind a
   common interface.
   * CellsFactory + `create_cells_factory(...)` → Uniform vs. Random
     initializers
   * `create_runner(...)` → VisualizationRunner vs. CycleFinder
1. Strategy Pattern: encapsulates the evolving‐state algorithm so you can swap
   it in/out at runtime.
   * `struct Dynamics { virtual void update(...) = 0; }`
   * Concrete strategies: `CollectiveDynamics` (and wrapped by
     `PrintDecorator`)
1. Decorator Pattern: demonstrates “extend behavior by composition” rather than
   inheritance.
   * `PrintDecorator` wraps any `Dynamics` implementation to add logging
     without modifying it
1. Separation of Concerns: clear modular division: argument parsing, object
   creation, simulation logic, and I/O/output are all in separate components.


## C++ specific design patterns

1. Variant + Visitor (a type-safe union): avoids a common base‐class for
   :w
   runners and still gives you dynamic dispatch.
   * `using RunnerVariant = std::variant<CycleFinder, VisualizationRunner>;`
   * `std::visit(...)` to dispatch `run()` and then handle the `CycleFinder`
     case
1. RAII & Smart Pointers
   * `std::unique_ptr` everywhere for automatic lifetime management and
     exception safety.
