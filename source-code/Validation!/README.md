# Scientific validation: harmonic oscillator energy conservation

This directory illustrates scientific validation, not software testing.  The
examples solve a harmonic oscillator, whose total energy should be conserved.
By comparing explicit Euler with a symplectic Boost.Odeint method, the examples
show that correct-looking code can still violate a known property of the model
when the numerical method is inappropriate.

## Harmonic oscillator with explicit Euler

`explicit_euler.cpp` solves the frictionless harmonic oscillator

```text
x'' = -(k/m) x
```

as the first-order system

```text
dx/dt = v
dv/dt = -(k/m) x
```

using the explicit Euler method.  For this model, the total energy

```text
E = 0.5*m*v*v + 0.5*k*x*x
```

should remain constant.  Explicit Euler is intentionally a poor method for this
problem: even when the code is implemented correctly, the energy drifts.  That
makes it a useful validation example because it shows that a simulation can
compile, run, and produce plausible-looking output while still violating a known
property of the physical model.

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

With default parameters:

```bash
./build/explicit_euler.exe > oscillator.tsv
```

With custom parameters:

```bash
./build/explicit_euler.exe <dt> <steps> <mass> <spring_constant> <x0> <v0>
```

For example:

```bash
./build/explicit_euler.exe 0.05 400 1.0 1.0 1.0 0.0 > oscillator.tsv
```

The output columns are:

```text
t    x    v    energy    relative_energy_error
```

Plotting `energy` or `relative_energy_error` versus `t` makes the validation
failure visible.

## Harmonic oscillator with Boost.Odeint velocity Verlet

`boost_velocity_verlet.cpp` solves the same model using Boost.Odeint's
`velocity_verlet` stepper.  Velocity Verlet is a symplectic method for
second-order systems.  For the harmonic oscillator, the energy is not exactly
constant at every floating-point step, but the error stays small and bounded
rather than growing steadily as it does with explicit Euler.

```bash
./build/boost_velocity_verlet.exe 0.05 400 1.0 1.0 1.0 0.0 > oscillator_verlet.tsv
```

This makes a useful side-by-side comparison:

```bash
./build/explicit_euler.exe 0.05 400 1.0 1.0 1.0 0.0 > oscillator_euler.tsv
./build/boost_velocity_verlet.exe 0.05 400 1.0 1.0 1.0 0.0 > oscillator_verlet.tsv
```

Compare the `relative_energy_error` column in both files.
