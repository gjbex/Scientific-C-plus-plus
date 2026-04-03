# Standard library algorithms

Code illustrations for chapter 10, Algorithms in Stroustrup's
"A tour of C++".

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Contents

1. `accumulate.cpp`: use `std::accumulate` with a lambda.
1. `find_if.cpp`: find elements using `std::find_if` and a closure.
1. `for_each.cpp`: modify vector elements using `std::for_each`.
1. `generate.cpp`: generate vector elements using `std::generate`.
1. `permutations.cpp`: enumerate permutations using `std::next_permutation`.
1. `particle_sort.cpp`: sort structs by mass and distance.
1. `count_clamp.cpp`: count values and clamp outliers with predicates.
1. `transform.cpp`: transform one sequence into another.
1. `zip_it.cpp`: combine two sequences with `std::transform`.
1. `find_words.cpp`: search text from standard input for the token `words`.
   Sample input: `text.txt`.
1. `distance.cpp`: compute distances from coordinate pairs read from standard input.
   Sample input: `coordinates.txt`.
1. `iota.cpp`: initialize a `std::valarray` using `std::iota`.
1. `points.cpp`: sort points using C++20's spaceship operator.
1. `CMakeLists.txt`: standalone build file for these examples.

## Sample data

- `text.txt`: input for `find_words.exe`.
- `coordinates.txt`: input for `distance.exe`.
