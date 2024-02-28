# Shapes

This is a comparison between various ways to deal with related types. We
consider three classes `Circle`, `Square` and `Triangle`.  We have many of such
objects and want to compute the sum of the areas of each of them.

1. `CRTP`: (Curiosly Repeating Template Pattern) the concrete shapes are
   derived from a template base class that implements the methods by statically
   casting to the derived type.
1. `Subclasses`: the various shape classes all inherit from an abstract base
   class `Shape` that defines a virtual function `area`.
1. `TypeErasure`: the various shape classes are not in any class hierarchy, but
   they all implement the `area` method, so we can use type erasure to compute
   the sum of their areas.
1. `Variant`: again, the various shape classes are not in any class hierarchy,
   but we use `std::variant` and `std::visit` to solve the issue.


## What is it?

1. `Subclasses`: implementation using inheritance.
1. `TypeErasure`: implementation using type erasure.
1. `Variant`: implementation using `std::variant` and `std::visit`.
1. `Crtp`: implementation using the Curiosly Repeating Template Pattern (CRTP).
1. `benchmark.sh`: Bash script to build the implementations using a given
   compiler, and running the benchmarks with a given size of the vector that
   contains the shapes.
