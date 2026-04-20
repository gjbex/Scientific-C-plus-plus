# Random Numbers From TOML

This example mirrors the functionality of `CLI11/random_default.cpp`, but it
reads the parameter values from a TOML configuration file instead of parsing
them from the command line.

The program reads these values from the `[random]` table:

1. `n`: number of random values to generate, default `1`
1. `a`: minimum value, default `0.0`
1. `b`: maximum value, default `1.0`
1. `seed`: required seed value

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

From the `TOML++/RandomNumbers` directory:

```bash
./build/random_from_config.exe
```

or with an explicit config path:

```bash
./build/random_from_config.exe config.toml
```
