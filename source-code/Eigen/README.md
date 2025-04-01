# Eigen

Eigen is a header-only library for linear algrebra in C++.

## What is it?

1. `matrix_product.cpp`: illustration of a matrix product using Eigen.
1. `read_matrix.cpp`: read matrix eleemnts from a text file to initialize an
    Eigen matrix.
1. `solve_eqns.cpp`: solve a set of two linear equantions using LU decomposition.
1. `CMakeLists.txt`: CMake file to build the applications.
1. `Mkl`: illustration how to use Intel's MKL to perform Eigen's
    computations under the hood.
1. `StringAlignment`: example of using integer matrices for string alignment
    using dynamic programming.


## How to build?

As there is no direct support in CMake to build applications that use Eigen, you
have to set the include directory for this header-only library.

```bash
$ cmake  -B build/  -S .  -DEIGEN_iNCLUDE_DIR=/usr/include/eigen3/
```

You should adapt the directory to the location of the library on your target
system.
