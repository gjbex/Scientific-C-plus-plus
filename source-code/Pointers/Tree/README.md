# Tree

Example of using various types of pointers to implement a binary tree.

## What is it?

* Classic pointers
  * `node.h`: definition of a template class for nodes in a tree data
      structure.
  * `tree.cpp`: main file to test node implementation.
* Shared pointers
  * `node_sptr.h`: definition of a template class for nodes in a tree data
      structure.
  * `tree_sptr.cpp`: main file to test node implementation.
* Unique pointers
  * `node_uptr.h`: definition of a template class for nodes in a tree data
      structure.
  * `tree_uptr.cpp`: main file to test node implementation.
* `CMakeLists.txt`: CMake file to build the applications.

The three tree drivers are also linked from `source-code/exercises.md` as
solutions for Pointers exercises comparing raw pointers, `std::unique_ptr`,
and `std::shared_ptr`.
