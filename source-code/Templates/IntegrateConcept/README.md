# IntegrateConcept

Example of using a template for duck typing, using a concept.


## What is it?

1. `integrand.h`: type declaration of the type for an integrand.
1. `simpson_quad.h`: class that implements Simpson quadrature.
1. `simpson_quad.cpp`: implementation of `SimpsonQuad` methods.
1. `gaussian_quad.h`: class that implementation Gaussian quadrature.
1. `gaussian_quad.cpp`: implementation of `GaussianQuad` methods.
1. `quadrature.h`: concept that defines the requirements for a quadrature
   method.
1. `main_quad.cpp`: main function that drives the quadrature using an algorithm
   determined at runtime, either based on `SimpsonQuad`, or `GaussianQuad`.
1. `CMakeLists.txt`: CMake file to build the application.
