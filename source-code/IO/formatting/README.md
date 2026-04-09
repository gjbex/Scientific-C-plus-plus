# Formatting

Examples of stream formatting, `std::format`, and `std::print`.

C++20 added `std::format`, which formats strings in a style similar to
Python's `str.format`. C++23 added `std::print` and `std::println` for
formatted output directly to a stream or the console.


## What is it?

1. `iomanip_formatting.cpp`: examples of stream formatting for floating-point
   values, field width, and fill characters.
1. `std_format.cpp`: simple illustration of `std::format`.
1. `print_format.cpp`: examples of basic usage of
   `std::format` and `std::print`. This target is only built when the standard
   library provides `<print>`.
1. `CMakeLists.txt`: CMake file to build the applications.
