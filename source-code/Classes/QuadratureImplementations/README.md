# Quadrature implementations

This directory collects seven implementations of the same quadrature example,
ordered roughly from runtime polymorphism to constrained compile-time
polymorphism.

## Overview

| Implementation | Dispatch mechanism | Main advantage | Main disadvantage |
| --- | --- | --- | --- |
| `Quadrature` | Abstract base class and virtual function | One uniform runtime interface; implementation can be selected and stored polymorphically at runtime | Indirect calls inhibit inlining, require heap allocation or another ownership wrapper, and the interface is fixed by the base class |
| `Quadrature_CRTP` | Curiously Recurring Template Pattern | Static dispatch with no virtual-call overhead while still sharing a common wrapper API | More template ceremony, harder diagnostics, and no heterogeneous runtime storage through one base pointer |
| `Quadrature_deduce_this` | Explicit object parameter (`this` deduction) | Keeps the static-dispatch benefits of CRTP while removing the "derived type as template argument" boilerplate | Requires a compiler with C++23 explicit-object-parameter support and is still less familiar than ordinary virtual dispatch |
| `Quadrature_duck_typing` | Unconstrained function template | Minimal coupling and very little framework code; any type with a compatible `integrate` member works | Interface requirements are implicit, so misuse tends to produce noisier template errors and weaker documentation |
| `Quadrature_duck_typing_template` | Unconstrained function template with a templated callable argument | Avoids `std::function` type-erasure overhead for the integrand while keeping the duck-typed interface lightweight | Interface requirements are still implicit, and templated member definitions must live in headers |
| `Quadrature_concept` | Concept-constrained template | Preserves static dispatch while making the required interface explicit and improving diagnostics | Still a compile-time interface only; unlike virtual dispatch, it does not by itself provide one runtime-polymorphic object type |
| `Quadrature_concept_template` | Concept-constrained template with a templated callable argument | Keeps explicit interface constraints while avoiding `std::function` overhead for the integrand | More template surface area, and the concept now depends on both the quadrature type and the callable type |

## How to read these examples

1. Start with `Quadrature` if you want the classic object-oriented design.
1. Move to `Quadrature_CRTP` to see how virtual dispatch can be replaced by
   static dispatch.
1. Compare `Quadrature_deduce_this` with `Quadrature_CRTP` to see how C++23
   reduces CRTP boilerplate.
1. Read `Quadrature_duck_typing` for the lightest-weight template-based
   formulation with a fixed `std::function` integrand type.
1. Compare `Quadrature_duck_typing_template` to see how templating the
   callable removes `std::function` overhead.
1. Move to `Quadrature_concept` to see how concepts make duck-typed
   requirements explicit.
1. Finish with `Quadrature_concept_template` to combine concept-checked
   quadrature types with a templated callable argument.

## Practical tradeoff

Runtime polymorphism is usually the better teaching example when the algorithm
must genuinely choose among unrelated implementations at runtime and pass them
around through one stable interface.

CRTP, `this` deduction, duck typing, and concepts are better fits when the
concrete quadrature type is known at compile time and performance, inlining,
and avoiding dynamic allocation matter more than runtime substitutability.

## Build note

`Quadrature_deduce_this` uses C++23 explicit object parameters. If your
compiler does not yet implement that feature, the other six variants still
build and run normally.
