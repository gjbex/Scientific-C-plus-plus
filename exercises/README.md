# Exercises

This directory contains hands-on exercises corresponding to the C++ slide deck.
Each Markdown file covers a specific topic, with step-by-step tasks and quiz
questions to reinforce key concepts.


## What is it?

1. [basics_of_cpp_exercises.md](basics_of_cpp_exercises.md): Core syntax: I/O,
   variables, expressions, branching, loops, functions, and debugging.
2. [user_defined_types.md](user_defined_types.md): Structs vs. classes,
   constructors/destructors, encapsulation, operator overloading.
3. [separate_compilation.md](separate_compilation.md): Splitting code into
   headers and source files, include guards, and CMake builds.
4. [inheritance.md](inheritance.md): Class inheritance, virtual functions,
   polymorphism via references, and object slicing.
5. [templates.md](templates.md): Function templates, class templates,
   specializations, default parameters, aliases.
6. [stl_containers.md](stl_containers.md): Exercises on `std::vector`,
   `std::set`, and `std::map` (insertion, search, ordering).
7. [stl_algorithms.md](stl_algorithms.md): Using `<algorithm>` and `<numeric>`:
   generation, transform, accumulate, sorting, partitioning, etc.
8. [stl_ranges.md](stl_ranges.md): C++20 `<ranges>` and `<views>`: lazy
   pipelines for filter, transform, iota, drop/take, and more.
9. [smart_pointers.md](smart_pointers.md): `std::unique_ptr`,
   `std::shared_ptr`, `std::weak_ptr`, and non-owning raw pointer/reference
   patterns.


## Prerequisites

- A C++17 toolchain (GCC/Clang/Intel) for most exercises.  
- C++20 support required for [stl_ranges.md](stl_ranges.md).  
- CMake 3.10+ for the separate compilation exercises.


## How to use

1. Open the Markdown file for the topic you want to practice.  
2. Follow the numbered steps in order, editing or creating code files as
   instructed.  
3. Build and run your code to verify expected behavior.  
4. Attempt the quiz questions to test your understanding.  

Happy coding!  
