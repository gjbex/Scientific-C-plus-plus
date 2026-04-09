# Ocean view

Given an array that represents heights of buildings, determine
which buildings have an ocean view.  A building has an ocean view
when all buildings between itself and the ocean are strictly smaller.
Consider the ocean position at the end of the array.

For example, consider buildings with heights [1, 9, 6, 8, 6, 3, 3],
then the implementation should return [1, 3, 4, 6].


## Build

```bash
cmake -S . -B build
cmake --build build
```

## Contents

1. `src/ocean_view.cpp`: two implementations of the algorithm, plus a helper
   that generates building heights.
1. `include/ocean_view.h`: public declarations.
1. `tests/main_test.cpp`: checks both implementations on the example above.
1. `benchmarks/main_timing.cpp`: timing driver for the first implementation.
1. `benchmarks/main_timing2.cpp`: timing driver for the second implementation.
1. `CMakeLists.txt`: standalone build file for this project.
