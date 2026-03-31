# Count-up generator

C++23 introduces a new feature called `generator` which is a type of coroutine
that can be used to generate a sequence of values lazily. This is a simple
example of a generator that generates the Fibonacci sequence.  Simple iterators
can be generated using higher-order functions to capture the generator's
properties.

**Note**: This code requires a C++23 compiler that supports the `generator`
feature, e.g., g++ 14.x or later.


## What is it?

1. `count_up.cpp`: C++ application that illustrates a configurable genertor
   using a higher-order function.
1. `CMakeLists.txt`: CMake file to build the application.
