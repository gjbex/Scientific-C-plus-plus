# Concepts

Concepts in C++ let you specify constraints on template parameters. They
express the requirements a type must satisfy before it can be used with a
template, which can improve readability and produce clearer diagnostics when
template instantiation fails.


## What is it?

1. `Simple`: a small example of using a concept to constrain template
   parameters for iterable types.
1. `DeduceThis`: a C++23 example showing how a concept can constrain a stop
   callback while explicit object parameters (`this auto&`) provide
   derived-type dispatch without CRTP.
