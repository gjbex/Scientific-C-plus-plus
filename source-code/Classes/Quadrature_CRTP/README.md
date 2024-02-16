# Quadrature

Example of using the Curiously Repeating Template Pattern (CRTP) for compile
time polymorphism.

## What is it?
1. `quad.h`: template class to wrap the actual class.
1. `simpson_quad.h`: derived class from `Quad` that derives from `Qeuad`.
1. `simpson_quad.cpp`: implementation of `SimpsonQuad` methods.
1. `gaussian_quad.h`: derived class from `Quad` that is derived from `Quad`.
1. `gaussian_quad.cpp`: implementation of `GaussianQuad` methods.
1. `main_quad.cpp`: main function that drives the quadrature using an
    algorithm determined at runtime, either based on `SimpsonQuad`, or
    `GaussianQuad`.  However, runtime polymorphism is avoided.
1. `CMakeLists.txt`: CMake file to build the application.
