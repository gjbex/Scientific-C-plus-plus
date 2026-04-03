# Numeric

Code illustrations that combine containers with numeric algorithms and
array-like storage.

# What is it?

1. `cosine_similarity.cpp`: illustration of `std::inner_product`, and when not
   to use it.
1. `kaprekar.cpp`: simple illustration of using `std::array` and `std::vector`,
   as well as `std::sort()` and `std::reverse()`, to find the Kaprekar constant.
1. `point_distances.cpp`: compute the maximum distance between points in 3D
   space with normally distributed coordinates. Illustrates both STL `array`
   and `vector` classes.
1. `stats.cpp`: use a vector to store data for statistical analysis, and
   compute descriptive statistics for data read from standard input.
1. `synthesizer.cpp`: use valarrays to represent signal values and compute the
   superposition of several cosine waves.
1. `mdspan_test.cpp`: experimental `std::mdspan` example. This source file is
   not part of `CMakeLists.txt` because the current toolchain does not provide
   `<mdspan>`.
1. `data/numbers.txt`: sample input for `stats.exe`.
1. `data/waves.txt`: sample input for `synthesizer.exe`.
1. `CMakeLists.txt`: CMake file to build the applications in this directory.
