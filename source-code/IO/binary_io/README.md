# Binary I/O

This is an example of doing binary I/O in C++.  It also illustrates interoperability
between C++ and Fortran with respect to binary files.


## What is it?

1 `triangular_matrix.f90`: Fortran application that writes an upper triangular
   matrix to a binary file, given its rows and columns.
1. `read_triangular_matrix.cpp`: C++ application that reads the binary file
   written by the Fortran application, and prints the matrix elements.
1. `CMakeLists.txt`: CMake file to build the applications.
