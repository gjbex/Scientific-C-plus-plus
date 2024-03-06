# Concepts

Concepts help to improve template error messages by providing a systematic
way for formulate constraints on the template parameters, typically the
types.


## What is it?

1. `iterable.h`: defintion of the iterable concept.
1. `main.cpp`: application that will fail to compile because the template
   constraints are not satisfied.
1. `CMakeLists.txt`: CMake file to build the applications.
