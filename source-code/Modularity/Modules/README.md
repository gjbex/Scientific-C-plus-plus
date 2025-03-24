# Modules

C++20 introduced modules to improve modular builds.

**Note:** this feature is supported by compilers only recently by g++ (14.x+) and by
recent versions of CMake (3.28+) when used with Ninja.


## What is it?

1. `fib.cppm`: C++ module that defines the Fibonacci function.
1. `main.cpp`: C++ application that uses the Fibonacci function.
1. `CMakeLists.txt`: CMake file to build the application.


## How to use it?

To build, use
```bash
$ cmake  -B build/  -S .  -G Ninja
$ cmake  --build build/
```
