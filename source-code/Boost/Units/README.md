# Units

Illustrations of the Boost units library.


## Waht is it?

1. `units_okay.cpp`: short program using units.
1. `units_not_okay.cpp`: short program using units.
1. `CMakeLists.txt`: CMake file to build the applications.


## How to use it?

To build the applications:
```bash
$ cmake  -B build/  -S .
$ cmake  --build build/
```

To compile the version that is incorrect
```bash
$ cmake  --build build/  --target not_okay
```
