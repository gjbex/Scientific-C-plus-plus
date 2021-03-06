# Pointers
Some illustrations of using pointers in C++.

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
* `DoubleLinkedList`: implementation of a double linked list
  that requires using raw pointers.
* `runtime_vs_compile_time.cpp`: illustrates how to determine the
  type of a derived class object at runtime when it is assigned to
  a pointer of the parent class.
