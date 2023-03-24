# Vcpkg

vcpkg is a package manager for C++.  It allows to install libraries and their
dependencies easily.  Installtion of vcpkg is straightforward, see the website
https://vcpkg.io/en/

## What is it?

1. `read_matrix.cpp`: read matrix eleemnts from a text file to initialize an
    Eigen matrix.
1. `matrix.txt`: text file representing a small matrix to use as input for
   the C++ application.
1. `CMakeLists.txt`: CMake file to build the applications.
1. `vcpkg_init.sh`: shell script for the CMake configuration using libraries
   installed using vcpkg.

## How to use?

Make sure that `VCPKG_DIR` points to the vcpkg directory (top-level).
```bash
$ export VCPKG_DIR="/path/to/vcpkg_directory"
```

To install Eigen3 using vcpkg:
```bash
$ $VCPKG_DIR/vcpkg install eigen3
```

To configure the CMake build:
```bash
$ mkdir -p build/
$ cmake -S . -B build/ \
    -DCMAKE_TOOLCHAIN_FILE=$VCPKG_DIR/scripts/buildsystems/vcpkg.cmake
```

Build as usual:
```bash
$ cmake --build build/
```
