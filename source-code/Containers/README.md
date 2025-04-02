# Containers

Code illustrations for chapter 9, Containers in Stroustrup's
"A tour of C++".

# What is it?

1. `tuple.cpp`: illustration of using STL `tuple` class.
1. `list.cpp`: illustration of using STL 'list` class.
1. `vector.cpp`: illustration of using STL `vector`class.
1. `set.cpp`: illustration of using STL `set` class.
1. `point_distances.cpp`: computes maximum distance between
    points in 3D space with coordinates drawn from a normal
    distribution.  Illustrates both STL `array` and `vector`
    classes.
1. `stats.cpp`: use a vector to store data for statistical analysis,
    computes descriptive statistics for data read from standard
    input.
1. `data.txt`: data file to perform some operations on.
1. `split_string.cpp`: use a vector to store parts of a splitted
    string, also illustrates `std::string::find()`.
1. `dim_nrs.cpp`: use a set to keep track of number occuring in
    a file.
1. `synthesizer.cpp`: use valarrays to represent signal values and
    compute the superposition of several cosine waves.
1. `diffusion_system.h`: decleration of `Particle` and 'System`
    classes to simulate diffusion through a medium.
1. `diffusion_system.cpp`: definitions of `Particle` and 'System`
    classes to simulate diffusion through a medium;  illustration
    of a priority queue.
1. `diffusion_main.ccp`: main function to drive the diffusion
    simulation.
1. `dim_nr_counts.cpp`: use a map to count occurences of number
    in a file.
1. `cosine_similarity.cpp`: illustration of `std::inner_product`,
    and when not to use it.
1. `aggregate_data.cpp`: use a map of `int` to a statistics class to
    aggregate data and compute average, minimum and maximum.
1. `multi_measurement.txt`: data file to use with `aggregate_data.exe`.
1. `rpn_calc.cpp`: implementation of a simple calculater for integer
    arithmetic expression in reverse Polish notation.  Illustrates use
    of a stack, a tuple, tokenizaiton, and simple exceptions.
1. `CMakeLists.txt`: CMake file to build the applications.
1. `SlidingWindow`: class template that uses a list to compute averages over a
   slidign window.
1. `kaprekar.cpp`: simple illustration of using `std::array` and `std::vector`
   as well as `std::sort()` and `std::reverse()` to find the Kaprekar constant.
