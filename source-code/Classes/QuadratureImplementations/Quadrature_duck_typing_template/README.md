# DuckTypingTemplate

Example of using a template for duck typing, with a templated callable
argument instead of `std::function<double(double)>`.


## What is it?

1. `simpson_quad.h`: class that implements Simpson quadrature with a templated
   callable argument.
1. `gaussian_quad.h`: class that implements Gaussian quadrature with a
   templated callable argument.
1. `gaussian_quad.cpp`: implementation of the `GaussianQuad` constructor.
1. `main_quad.cpp`: main function that drives the quadrature using an
   algorithm determined at runtime, either based on `SimpsonQuad`, or
   `GaussianQuad`.
1. `CMakeLists.txt`: CMake configuration file to build the application.

## Build

```bash
cmake -S . -B build
cmake --build build -j
```

## Run

```bash
./build/quad.exe simpson
./build/quad.exe gaussian
```
