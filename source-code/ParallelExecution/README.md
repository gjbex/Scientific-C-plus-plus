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
1. `CMakeLists.txt`: CMake file to build the applications
