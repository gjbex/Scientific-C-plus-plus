# Quadrature dispatch benchmark

This directory benchmarks the existing quadrature variants without
modifying their source trees:

- `../Quadrature`: runtime polymorphism via a virtual base class;
- `../Quadrature_CRTP`: compile-time polymorphism via CRTP;
- `../Quadrature_duck_typing`: compile-time polymorphism via unconstrained
  templates.
- `../Quadrature_duck_typing_template`: same duck-typed dispatch, but with a
  templated callable argument instead of `std::function`.

Each benchmark executable links against only one implementation family so the
existing global class names can remain unchanged.

## What is measured

Each executable:

1. constructs one quadrature object outside the timed region;
1. repeatedly integrates the same smooth function over five symmetric
   intervals;
1. prints elapsed wall time, average nanoseconds per integral, and a checksum.

The checksum acts as a minimal sanity signal and keeps the optimizer from
dropping the repeated integrations.

## Important caveat

`Quadrature`, `Quadrature_CRTP`, and `Quadrature_duck_typing` still pass the
integrand as `std::function<double(double)>`. `Quadrature_duck_typing_template`
passes the callable as a template parameter, so it avoids that type-erasure
cost and can inline the integrand.

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
```

## Run one case

```bash
./build/bench_runtime.exe 2000000 100
./build/bench_crtp.exe 2000000 100
./build/bench_duck_typing.exe 2000000 100
./build/bench_duck_typing_template.exe 2000000 100
```

Arguments are:

```text
<repetitions> <simpson_panels>
```

## Run the comparison table

```bash
./run_benchmarks.py --build-dir build --repetitions 2000000 --warmup-runs 2 --runs 7 --simpson-panels 100
```

The script accepts named command-line options via `--help` and:

1. prints machine, compiler, git, and OpenMP environment context;
1. performs a short checksum sanity check for each dispatch variant;
1. times each executable with `hyperfine --warmup` when available, otherwise
   the `scientific-cli-benchmark` skill's `simple_benchmark.py` helper;
1. reports mean runtime, runtime variability, average nanoseconds per integral,
   the checksum, and the exact command line.

For very short runs, increase `repetitions_per_process` so each command takes
comfortably more than a few milliseconds.
