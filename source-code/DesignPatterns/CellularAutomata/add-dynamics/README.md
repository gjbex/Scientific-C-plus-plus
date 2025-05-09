# Example: Adding a new Dynamics subclass

This directory (`add-dynamics/`) illustrates the minimal set of changes
required to introduce a new `Dynamics` implementation (shown here as
`IndividualDynamics`) into the project.

1. New files:  these define a new `struct IndividualDynamics : public Dynamics`
   and implement its `update(Cells& cells)` method.
  - `individual_dynamics.h`
  - `individual_dynamics.cpp`
2. Build system: `CMakeLists.txt`: add `individual_dynamics.cpp` to the
   `cellular_automata.exe` target source list (in addition to the existing
   dynamics and utility files).
3. CLI option
  - `utils.h`: extend `CAOptions` with a new field, i.e., `std::string
    dynamics;`.
  - `utils.cpp`: in `parse_arguments()`, add a `--dynamics` option (default
    is be "collective") and validate allowed values (i.e., "collective" or
    "individual").
4. Factory logic
  - `utils.cpp`: include `individual_dynamics.h`.
  - In `create_dynamics()`, branch on `options.dynamics`:
    ```cpp
    if (options.dynamics == "individual") {
      dyn = std::make_unique<IndividualDynamics>(rule, options.nr_cells);
    } else {
      dyn = std::make_unique<CollectiveDynamics>(rule, options.nr_cells);
    }
    ```
  - Preserve the existing `PrintDecorator` wrapping when `options.verbose` is
    true.
5. Documentation
  - Update the top-level `README.md` to mention the new files.

By following these steps, your new `Dynamics` subclass will integrate with the
factory-based construction, decorator support, and command-line interface already
in place, without modifying the core simulation loop or existing implementations.
