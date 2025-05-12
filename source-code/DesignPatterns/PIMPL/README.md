# PIMPL

Pointer to IMPLementation idiom example.


## What is it?

1. `quad.h`: interface that uses a pointer to the implementaion.
1. `simpson_quad.cpp`: implementation of the Simpson quadrature method.
1. `gaussian_quad.cpp`: implementation of the Gaussian quadrature method.
1. `main_quad.cpp`: main function that drives the quadrature.
1. `CMakeLists_simpson.txt`: CMake file for the Simpson quadrature.
1. `CMakeLists_gauss.txt`: CMake file for the Gaussian quadrature.


## Denonstration

Build the application with Simpson quadrature:
```bash 
$ cp -r CMakeLists_simpson.txt CMakeLists.txt
$ cmake -B guild/ -S .
$ cmake --build build
```
Observe the build artifacts, especially `main_quad.o` and `simpson_quad.o`.

Now switch to the Gaussian quadrature:
```bash
$ cp -r CMakeLists_gauss.txt CMakeLists.txt
$ cmake --build build
```
Note that only `gaussian_quad.o` is built, while `main_quad.o` is reused. This
is because the interface remains unchanged, and only the implementation
changes. The PIMPL idiom allows for this separation of interface and
implementation, leading to faster builds and better encapsulation.
