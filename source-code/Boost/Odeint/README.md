# Odeint
Some illustrations of using the Boost Odeint C++ library solving a set
of ordinary differential equations.

## What is it?
1. [lorenz.cpp](lorenz.cpp): the Lorenz attractor implemented using the Boost
    ordinary differential equation solver.  Also illustrates
    currying (with `std::bind`) to avoid parameters as global
    variables.
1. [plot_lorenz.plt](plot_lorenz.plt): Gnuplot script to plot curve for Lorenz system.
1. [Makefile](Makefile): make file to build the code.
