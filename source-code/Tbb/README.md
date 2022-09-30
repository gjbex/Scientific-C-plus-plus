# Tbb
Intel Threading Building Blocks (TBB) is a library for multithreaded
programming in C++.

## What is it?
1. [trivial_parallel_for.cpp](trivial_parallel_for.cpp): comparing `std::for_each` and `tbb::parallel_for`
    syntax and semantics.
1. [simplest_parallel_for.cpp](simplest_parallel_for.cpp): simple application illustrating a
    `tbb::parallel_for` loop over a `std::valarray`.
1. [simple_parallel_for.cpp](simple_parallel_for.cpp): simple application illustrating a
    `tbb::parallel_for` loop over a `std::valarray` using blocked ranges.
1. [trivial_parallel_reduce.cpp](trivial_parallel_reduce.cpp): comparing `std::valarray::sum` and
    `tbb::parallel_reduce`.
1. [grain_size_parallel_for.cpp](grain_size_parallel_for.cpp): illustrates using a grain size, rather than
    automatic distribution.
1. [simple_parallel_reduce.cpp](simple_parallel_reduce.cpp): simple application illustraing a
    `tbb::parallel_reduce` over a `std::valarray`.
1. [vector_parallel_reduce.cpp](vector_parallel_reduce.cpp): simple application illustraing a
    `tbb::parallel_reduce` over a `std::vector`, using `std::accumulate`,
    rather than an explicit loop for the reduction.
1. [stats_parallel_reduce.cpp](stats_parallel_reduce.cpp): reduction example using a class rather than lambda
   functions.
1. [fibonacci_tasks.cpp](fibonacci_tasks.cpp): implementation of the Fibonacci function using TBB
    tasks.
1. [Makefile](Makefile): make file to build the applications.
1. [flow_graph.cpp](flow_graph.cpp): simple flow graph example.
1. [build.sh](build.sh): bash script to conveniently build the application on
    the VSC cluster.
1. [run.sh](run.sh): bash script to conveniently run the application on
    the VSC cluster.
1. [JuliaSet](JuliaSet): Julia set implementation using TBB and OpenMP.
1. [LineOfSight](LineOfSight): illustration of `tbb::parallel_scan`.
1. [Tree](Tree): illustration of parallel tree traversal.
