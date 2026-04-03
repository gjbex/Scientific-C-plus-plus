# This-deduction

This is an illustration of how to replace CRTP with C++23 explicit object
parameters (`this auto&`). However, this example is not quite trivial since
overload resolution also has to account for the signature of a function that is
passed as an argument to a method.

This can be done by defining a concept that checks the signature of the
function and then using this concept in the method that takes the function as
an argument. The method can then use the deduced object type to call the
derived implementation and pass the correct simulation type to the stop
callback.

This example implements a simulation framework that can be used to implement
different types of simulations. Building it requires a compiler with support
for C++23 explicit object parameters; `main_dice_avg.cpp` also uses
`std::ranges::views::enumerate`.


## What is it?

1. `simulation.h`: This file contains the definition of the `Simulation` class
   that provides `step()`, a fixed-step `run(max_nr_steps)` overload, and a
   stop-callback `run(stop_function)` overload constrained by the
   `StopCondition` concept. Derived classes must provide
   `step_implementation()`.
1. `dice_simulation.h`: this class derives from `Simulation` and implements a
   simulation of rolling dice. Its `step_implementation()` rolls one die and
   prints the result.
1. `main_dice.cpp`: application that runs `DiceSimulation` once with a fixed
   step count and once with a stop callback.
1. `dice_avg_simulation.h`: this class derives from `Simulation` and implements a
   dice-roll histogram simulation. Its `step_implementation()` updates the
   six-bin throw distribution; the threshold-based stop condition is defined in
   `main_dice_avg.cpp`.
1. `main_dice_avg.cpp`: application that runs `DiceAvgSimulation` until
   `(max(distribution) - min(distribution)) / average(distribution)` drops
   below an optional command-line threshold, then prints the distribution and
   step count.
1. `CMakeLists.txt`: CMake file that builds `dice.exe` and `dice_avg.exe` with
   C++23 enabled.
