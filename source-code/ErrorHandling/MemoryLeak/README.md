# Memory leak

Code illustrating a memory leak created by inappropriate exception
handling.

# What is it?
1. `memory_leak.cpp`: illustration of a memory leak caused by bad exception
    handling.
1. `memory_leak_fixed.cpp`: illustrates using RAII to ensure correct resource
    management.
1. `Makefile`: make file for these examples.

## How to use it?
Run `memory_leak.exe` and `memory_leak_fixed.exe` through valgrind with -1 and 5
as arguments and note the difference.
