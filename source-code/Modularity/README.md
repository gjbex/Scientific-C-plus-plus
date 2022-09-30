# Modularity
Code illustrations for chapter 3, Modularity in Stroustrup's
"A tour of C++".

# What is it?
1. [NamespaceParticles](NamespaceParticles): example of defining a namespace.
1. [Patricles](Patricles): example of separate compilation.
1. [PatriclesCMake](PatriclesCMake): example of build using CMake.
1. [Stats](Stats): example of separate compilation.
1. [fac.cpp](fac.cpp): illustrates exception handling.
1. [memory_leak.cpp](memory_leak.cpp): illustration of a memory leak caused by bad exception
    handling.
1. [memory_leak_fixed.cpp](memory_leak_fixed.cpp): illustrates using RAII to ensure correct resource
    management.
1. [Makefile](Makefile): make file for these examples.

## How to use it?
Run `memory_leak.exe` and `memory_leak_fixed.exe` through valgrind with -1 and 5
as arguments and note the difference.
