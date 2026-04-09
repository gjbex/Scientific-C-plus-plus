# Concepts simple example

Concepts help to improve template error messages by providing a systematic
way to formulate constraints on the template parameters, typically the
types.


## What is it?

1. `iterable.h`: definition of the `Iterable` concept in terms of
   `std::begin`, `std::end`, and `std::input_iterator`.
1. `main.cpp`: application that successfully prints `std::vector<int>` and
   `std::span<float>` values through two concept-constrained function
   templates. Uncomment the final two lines in `main()` to trigger a concept
   diagnostic for a non-iterable argument.
1. `CMakeLists.txt`: CMake file that builds `iterable.exe` with C++23 enabled.
