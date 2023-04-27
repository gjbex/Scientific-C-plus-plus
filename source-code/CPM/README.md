# CPM

Very lightweight package manager for C++ to be used with CMake.

## What is it?

1. `main.cpp`: very simple application that uses the `fmt` library
   to write an `std::vector` to standard output.
1. `CMakeLists.txt`: CMake file that builds the applications, it
   downloads CPM if necessary, and downloads and install the
   dependencies defined in it.

## How to use?

To build the applications, no special action is required:
```bash
$ cmake  -B build/  -S .
$ cmake  --build build/
```

Note that when you clean the build or remove the build directory CPM
and the build dependencies have to be downloaded and built again.

To use a source cache, configure CMake as follows:
```bash
$ cmake -B build/  -S .  -DCPM_SOURCE_CACHE=$HOME/cpm_cache
```
