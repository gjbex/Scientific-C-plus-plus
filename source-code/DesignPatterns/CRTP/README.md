# Curiously Repeating Template Pattern (CRTP)

This is an illustration of the Curiously Repeating Template Pattern (CRTP) in
C++. It is a design pattern that allows a class to inherit from a template
class that takes the derived class as a template parameter. This pattern is
often used to implement static polymorphism, where the behavior of a class can
be determined at compile time rather than at runtime.

This example implements a simulation framework that can be used to implement
different types of simulations.


## What is it?

1. `simulation.h`: This file contains the definition of the `Simulation` class
   template, which is the base class for all simulations. It defines a function
   `run()` that calls a function `step_implementation()` that must be
   implemented by derived classes.
1. `dice_simulation.h`: this class derives from `Simulation` and implements a
   simulation of rolling dice. It implements the `step_implementation()`
   function that rolls a die and print the result.
1. `main_dice.cpp`: application to drive the `DiceSimulation`.
1. `dice_avg_simulation.h`: this class derives from `Simulation` and implements a
   simulation of rolling dice until the deviation from the average is below a
   given threshold. It implements the `step_implementation()` function that keeps
   track of the distribution.
1. `main_dice_avg.cpp`: application to drive the `DiceAvgSimulation`.
1. `CMakeFile.txt`: CMake file to build the applications.
