# Container choices

Possible solutions for the container selection exercise.
These are example answers, not the only acceptable ones.  Participants
should be encouraged to consult standard library references such as
`cppreference.com` and justify their choice based on semantics,
ownership, and expected usage patterns.

1. Fixed-size calibration constants: `std::array`
   The number of values is known at compile time, and the data are stored
   contiguously.
1. Sequence of measurements of unknown length: `std::vector`
   Values can be appended efficiently, and contiguous storage is useful for
   numeric work.
1. Unique sample identifiers: `std::unordered_set`
   It stores unique keys and provides efficient lookup.
1. Mapping from sample ID to temperature: `std::unordered_map`
   This models key-value associations directly.
1. Undo history: `std::stack`
   The most recent action is undone first, so LIFO semantics are appropriate.
1. Print queue: `std::queue`
   Jobs are typically processed in arrival order, so FIFO semantics fit.
