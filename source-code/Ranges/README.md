# Ranges

Ranges help to deal more conveniently with STL containers, and the
composition of algorithms.  Part of this functionality is rolled into
the C++20 standard.

## What is it?
1. `simple.cpp`: very simple example of using ranges.
1. `transform_accumulate.cpp`: simple example of chaining a
    transformation and an accumulator on a vector.
1. `classic_stl_to_ranges.cpp`: from classic STL algorithms to
   ranges and views.
1. `input_ranges.cpp`: example of using an input stream view and a
   range copy.
1. `data.txt`: small data file to use for `input_ranges.cpp` application.
1. `CMakeLists.txt`: CMake file to build the applications.

*Note:* you will need at least g++ 10.x to compile this succesfully.
