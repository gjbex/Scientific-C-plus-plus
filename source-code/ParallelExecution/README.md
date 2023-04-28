# Parallel execution

The C++ STL library for algorithms has the possibility to specify
execution policies.  This allows algorithms to use Threading Building
Blocks (TBB) under the hood.

**Note:**: you need TBB installed for this to work.


## What is it?

1. `main_no_policy.cpp`: application that sorts a vector with no policies
   specified.
1. `main_seq.cpp`: application that sorts a vector with a sequential policy
   specified.
1. `main_par.cpp`: application that sorts a vector with a parallel policy
   specified.
1. `data.h`: some functions to create data.
1. `data.cpp`: implementation of functions to create data.
1. `main_transform_seq.cpp`: application that transforms elements of a vector
   with a sequential policy.
1. `main_transform_par.cpp`: application that transforms elements of a vector
   with a parallel policy.
1. `main_transform_par_unseq.cpp`: application that transforms elements of a vector
   with a parallel unsequenced policy.
1. `functions.h`: some functions to use to transform data elements.
1. `functions.cpp`: implementation of functions to use to transform data elements.
1. `CMakeLists.txt`: CMake file to build the applications
