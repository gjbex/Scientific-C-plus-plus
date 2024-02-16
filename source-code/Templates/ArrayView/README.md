# Arrays views

A lightweight template to provide multi-dimensional access to
a one-dimensional data structure such as a `std::vector`.  This
illustrates the use of variadic templates to specify the dimensions
of the view, as well as error checking at compile time when an
incorrect number of indices is used when accessing the elements.


## What is is?

1. `array_view.h`: definition of the `ArrayView` template.
1. `test_array_views.cpp`: C++ application to test the template.
1. `CMakeLists.txt`: CMake file to build the applications.
