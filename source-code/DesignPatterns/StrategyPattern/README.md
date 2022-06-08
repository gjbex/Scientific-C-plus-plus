# Strategy pattern

The strategy pattern allows to inject functionality at runtime into
objects or functions/method calls.

## What is it?

1. `automaton_runner.h`: class that runs a given cellular automaton.
   It accepts a strategy in its method to evolve the automaton.
1. `automaton_runner.cpp`: implementation of the `AutomatonRunner`
   class.
1. `cycle_finder.h`: class that implements a non-trivial strategy.
1. `cycle_finder.cpp`: implmentation of the `CycleFinder` class
   methods.
1. `main.cpp`: application to run cellular automata.
1. `Makefile`: make file to build the applications.
