# Algorithm choices

Possible solutions for the STL algorithm selection exercise.
These are example answers, not the only acceptable ones.  Participants
should be encouraged to consult standard library references such as
`cppreference.com` and justify their choice based on semantics and
clarity, not only familiarity.

1. Find the first negative value in a sequence: `std::find_if`
   This searches until the first element satisfies a predicate.
1. Count how many values are above a threshold: `std::count_if`
   This counts all elements for which the predicate is true.
1. Clamp all values to a fixed interval: `std::replace_if`
   Use it to replace values above the upper bound and below the lower bound.
1. Sort particles by mass: `std::sort`
   Provide a comparator or projection-like comparator based on the mass field.
1. Compute the sum of a sequence: `std::accumulate`
   This is the standard reduction algorithm for sums and similar folds.
1. Apply a function to every element of a sequence: `std::for_each`
   Use this when the goal is to visit each element and perform an action.
1. Combine two sequences element by element: binary `std::transform`
   This is the standard algorithm for pairwise combination into an output range.
1. Generate an arithmetic progression: `std::generate`
   Supply a stateful generator that returns the next value in the progression.
