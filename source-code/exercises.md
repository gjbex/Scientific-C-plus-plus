# Exercises
These are some exercises you can do as part of the C++ training. Chapters
refer to Bjarne Strustroup's "A tour of C++".

## Table of contents

  * [The basics](#basics)
  * [User defined types](#udfs)
  * [Separate compilation and error handling](#modularity)
  * [Classes](#classes)
  * [Templates and functional programming](#templates)
  * [Containers](#containers)
  * [Algorithms](#algorithms)
  * [Numerics](#numerics)
  * [Pointers](#pointers)
  * [Strings and regular expressions](#regexes)
  * [i/O streams](#iostreams)
  

## <a name="basics">The basics (Chapter 1)</a>

  1. Write a program that writes a greeting to standard output. When
    a command line argument is provided, e.g., `Bjarne`, the greeting
    should be `hello Bjarne!`, otherwise `hello world!`.
    ([Solution](Basics/hello.cpp))
  1. Write a program that reads from standard input, and interprets a
    string as a name.  It will write a greeting to standard output,
    unless it reads `quit`, then it will print `Bye!`.
    ([Solution](Basics/talk.cpp))
  1. Write a program that computes the factorial function for a number
    specified on the command line.
    ([Solution](Basics/fac.cpp))
  1. Write a program that computes the greatest common divisor of
    two integers specified on the command line.
    ([Solution](Basics/gcd.cpp))
  1. Write a program that uses three functions to
      1. initialize an array of `double` with the square roots of 0.0 up
        to the array's length minus one;
      2.  print that array to standard output; and
      3. compute the sum of the array elements, which is printed by the
        program.
    ([Solution](Basics/arrays.cpp))
  1. Write a program that implements two functions, the first to swap
    the values of two `int` variables, the second to swap the values of
    two `double` variables.  Print the values before and after calling
    the functions.  Use function overloading.
    ([(Solution](Basics/swap.cpp))
  1. Write a program that reads x and y coordinates from standard input,
    it computes and writes the distance of the corresponding point with
    respect to the origin.
    ([Solution](Basics/col_dist.cpp))
  1. Write a program that reads integers from standard input, and computes
    the sum. It should ignore input lines that start with `#`.
    ([Solution](Basics/data_parser.cpp))


## <a name="udfs">User defined types (Chapter 2)</a>

  1. Write a program that manipulates particles.  A particle has x, y and z
    coordinates, as well as mass. Write a function that returns a structure
    initialized to given coordinates and mass, i.e., "creates" a particle.
    Write a function that moves a particle a given distance in the x, y and
    z directions. Write a function that computes the Euclidean distance
    between two given particles. Overload the `<<` operator to generate
    a representation of a particle as `(<x>, <y>, <z>), mass = <mass>`.
    ([Solution](UserDefinedTypes/struct_particles.cpp))
  1. Represent the particles of the previous exercise as a class, the
    functions will be the constructor and methods respectively.
    ([Solution](UserDefinedTypes/class_particles.cpp))
  1. Extend the previous exercise so that particles can have a charge. The
    charge is represented as an `enum class`.
    ([Solution](UserDefinedTypes/charged_particles.cpp))
  1. Create a class that represents statistical information for a stream of
    data.  Once an object is created, data (`double` numbers) can be added
    one at the time.  At any time, the current average can be obtained.
    ([Solution](UserDefinedTypes/streaming_stats.cpp))


## <a name="modularity">Separate compilation and error handling (Chapter 3)</a>

  1. Represent particles by a class as in the previous chapter, but split
    the code over three files, a header file with the class definition,
    a C++ source file with the class methods' definitions, and a C++
    source file that defines the `main` function. Write a make file to
    build the application.
    ([Solution](Modularity/Particles))
  1. Create a class that represents statistical information for a stream of
    data.  Once an object is created, data (`double` numbers) can be added
    one at the time.  At any time, the current average can be obtained.
    ([Solution](Modularity/Stats)),
  1. Write a program that gets an integer from the command line, checks
    whether it is positive, and computes the factorial function of it.
    Do proper error handling, i.e., generate an error if no value is
    specified on the command line, when the value specified doesn't
    represent an integer, and when the integer is negative.
    ([Solution](Modularity/fac.cpp))


## <a name="classes">Classes (chapter 4)</a>

  1. Represent static particles by a class as in the previous chapter.
    Next, use this class as a base class for particles that have a
    velocity. Add a `move` method to this class that overrides the one
    in the base class, taking only a single argument, the time delta
    during which the particle will move.
    ([Solution](Classes/Particles))
  1. Create a class that represents statistical information for a stream of
    data.  Objects of this class only compute the average.  Use this as
    a base class for a derived class that can also compute the standard 
    deviation
    ([Solution](Classes/Stats))
  1. Create an abstract base class that represent algorithms for
    computing the quadrature of functions. Create two derived classes,
    the first implements Simpson's method, the other the Gauss method. The
    main function takes a command line argument specifying which method
    to use to compute the numerical integral of a function over an
    interval.
    ([Solution](Classes/QuadratureImplementations/Quadrature))
    

## <a name="templates">Templates and functional programming interludes (chapter 5)<a/>

  1. Implement a template for a functions that will swap the values of
    two variables passed by reference for any type (both variables have
    the same type).
    ([Solution](Templates/swap.cpp))
  1. Implement a template for a function that will compute the sum of its
    arguments, regardless of the number of arguments.
    ([Solution](Templates/sum.cpp))
  1. Implement two classes for performing a quadrature algorithms on a
    function over an interval.  Both classes are unrelated, but implement
    a method `integrate` with the same signature. Write a template functions
    that performs the numerical integration of a given function using
    either algorithm for an increasing size of the integration interval
    e.g., `[-1.0, 1.0]` to `[-5.0, 5.0]` in increments of 1.0.
    ([Solution](Templates/DuckTyping))
  1. Write a function that computes the Euclidean distance between two
    points in 3D.  The points are represented as a length 3 array. Use
    type aliasing to make the code easier to read.
    ([Solution](Templates/points.cpp))
  1. Implement a class that represents a function to compute the angle
    of a swinging pendulum as a function of time.  The constructor fixes
    the frequency.
    ([Solution](Templates/pendulum_func_obj.cpp))
  1. Write a program that implements a function with two arguments to
    compute the angle of a swinging pendulum.  The first is time, the
    second the pendulum's frequency.  Use `std::bind` to create a new
    function that has the time as a single argument. Print the values in
    the range `[0.0, 20.0]`.
    ([Solution](Templates/pendulum_bind.cpp))
  1. Write a program that implements a function with two arguments to
    compute the angle of a swinging pendulum.  The first is time, the
    second the pendulum's frequency.  Write a lambda function that has
    the time as a single argument. Print the values in the range
    `[0.0, 20.0]`.
    ([Solution](Templates/pendulum_bind.cpp))


## <a name="containers">Containers (chapter 9)</a>

  1. Write a program that reads exactly 10 floating point values from
    standard input into a `std::array<double, 10>`.  It should compute
    the square of each value, and print the sum of the squared values.
    ([Solution](Containers/sequence/array_sum_squares.cpp))
  1. Write a program that reads floating point values from standard input
    into a `std::vector<double>`.  Once all values are read, it computes
    and prints the minimum, maximum, average and median of the data.
    ([Solution](Containers/sequence/vector_stats.cpp))
  1. Write a program that represents a particle as a
    `std::tuple<double, double, double, double>` where the values are
    x, y, z and mass respectively.  Implement a function that computes
    the Euclidean distance between two such particles, and a function
    that prints a particle in a readable format.
    ([Solution](Containers/sequence/particle_tuple.cpp))
  1. Write a program that reads words from standard input, and uses an
    `std::unordered_set<std::string>` to determine how many distinct
    words occur in the input.  The final result is written to standard
    output.
    ([Solution](Containers/associative/distinct_words.cpp))
  1. Write a program that reads words from standard input, and uses an
    `std::unordered_map<std::string, std::size_t>` to count how often
    each word occurs.  Print the word with the highest frequency and its
    count.
    ([Solution](Containers/associative/word_frequencies.cpp))
  1. Write a program that implements a reverse Polish notation
    calculator using a `std::stack<double>`.  It should support at least
    the operators `+`, `-`, `*` and `/`.
    ([Solution](Containers/stacks_queues/rpn_calc.cpp))
  1. Write a program that simulates a task queue using a
    `std::queue<std::string>`.  It reads commands from standard input:
    `push <task>` adds a task to the queue, `pop` removes and prints the
    next task, and `quit` stops the program.
    ([Solution](Containers/stacks_queues/task_queue.cpp))
  1. Write a program that simulates triage in an emergency room using a
    `std::priority_queue`.  Each patient has a name and an integer
    priority.  Patients with the highest priority are treated first.
    ([Solution](Containers/stacks_queues/er_triage.cpp))
  1. For each of the following situations, choose the most appropriate
    standard container and motivate your choice briefly.  You are
    encouraged to browse the standard library documentation, e.g., on
    `cppreference.com`, to discover relevant container types and
    container adaptors beyond those discussed in the training material:
    fixed-size calibration constants; a sequence of measurements of
    unknown length; unique sample identifiers; a mapping from sample ID
    to temperature; an undo history; a print queue.
    ([Solution](Containers/container_choices.md))


## <a name="algorithms">Algorithms (chapter 10)</a>

  1. Write a program that uses `std::find_if` to search a collection of
    integers.  For several target values, it should report the first
    element in the collection that is larger than the target, or state
    that no such element exists.
    ([Solution](Algorithms/std-algorithms/find_if.cpp))
  1. Write a program that uses `std::generate` to initialize a vector
    with values in an arithmetic progression.
    ([Solution](Algorithms/std-algorithms/generate.cpp))
  1. Write a program that uses `std::for_each` to modify all elements of
    a vector.
    ([Solution](Algorithms/std-algorithms/for_each.cpp))
  1. Create a structure to represent particles with coordinates and mass.
    Store a number of particles in a vector, and use `std::sort` to order
    them first by mass, and then by distance from the origin.
    ([Solution](Algorithms/std-algorithms/particle_sort.cpp))
  1. Write a program that uses `std::count_if`, `std::count`, and
    `std::replace_if` on a collection of integers.  It should count the
    number of negative, zero, and positive values, and then clamp all
    values to the interval `[-5, 5]`.
    ([Solution](Algorithms/std-algorithms/count_clamp.cpp))
  1. Write a program that uses `std::transform` to evaluate a quadratic
    function for a range of x values, and prints the resulting x-y pairs.
    ([Solution](Algorithms/std-algorithms/transform.cpp))
  1. Write a program that uses the binary form of `std::transform` to
    combine two sequences element by element into a third sequence.
    ([Solution](Algorithms/std-algorithms/zip_it.cpp))
  1. Write a program that uses `std::accumulate` to compute the sum of
    the squares of the first `n` integers.
    ([Solution](Algorithms/std-algorithms/accumulate.cpp))
  1. Write a program that reads coordinate pairs from standard input and
    computes their distances from the origin.
    ([Solution](Algorithms/std-algorithms/distance.cpp))
  1. Rewrite a simple loop over a container using C++ ranges.  Create a
    filtered view of the data and print only the selected values.
    ([Solution](Ranges/simple.cpp))
  1. Write a program that composes a transformation with an accumulation
    using ranges or views, instead of building an intermediate container
    explicitly.
    ([Solution](Ranges/transform_accumulate.cpp))
  1. Take a small example that uses classic STL algorithms and iterators,
    and rewrite it using ranges and views.  Compare the readability of
    both versions.
    ([Solution](Ranges/classic_stl_to_ranges.cpp))
  1. Read values from a file or standard input using an input-range view,
    and copy or process them without writing an explicit input loop.
    ([Solution](Ranges/input_ranges.cpp))
  1. Iterate over a range together with element indices, and print both
    index and value.
    ([Solution](Ranges/enumerate.cpp))
  1. Sort a collection of structures using a ranges algorithm and a
    projection to select the field to sort on.
    ([Solution](Ranges/projection.cpp))
  1. Sort a collection of particles by mass using a ranges algorithm, and
    compare that approach with writing a custom comparator manually.
    ([Solution](Ranges/particle_sort.cpp))
  1. For each of the following situations, choose the most appropriate
    STL algorithm and motivate your choice briefly.  You are encouraged
    to browse the standard library documentation, e.g., on
    `cppreference.com`, to discover suitable algorithms beyond those
    discussed in the training material:
    find the first negative value in a sequence; count how many values
    are above a threshold; clamp all values to a fixed interval; sort
    particles by mass; compute the sum of a sequence; apply a function
    to every element of a sequence; combine two sequences element by
    element; generate an arithmetic progression.
    ([Solution](Algorithms/algorithm_choices.md))


## <a name="numerics">Numerics (chapter 12)</a>

  1. Write a program that uses `std::complex<double>` to perform basic
    complex arithmetic, and prints the real part, imaginary part, and
    norm of the result.
    ([Solution](Numerics/complex.cpp))
  1. Write a program that computes and prints the minimum and maximum
    values for several integer types using `std::numeric_limits`.
    Extend it to test floating point values for infinity and NaN.
    ([Solution](Numerics/limits.cpp))
  1. Write a program that compares `std::numbers::pi` with `M_PI`, and
    illustrates why templated numeric constants are preferable when
    working with different floating point types.
    ([Solution](Numerics/numbers_pi_versus_M_PI.cpp))
  1. Write a program that uses a random device to seed a pseudo-random
    number engine, and then samples values from a normal distribution.
    ([Solution](Numerics/random.cpp))
  1. Extend the previous exercise to sample from multiple distributions
    that share the same engine.
    ([Solution](Numerics/multiple_distr.cpp))
  1. Write a program that computes points in a Julia set using complex
    arithmetic, and writes the results in a format suitable for plotting.
    ([Solution](Numerics/julia.cpp))
  1. Use a linear algebra library to compute a matrix-vector product.
    ([Solution](Armadillo/matrix_vector_product.cpp))
  1. Use a linear algebra library to compute the singular value
    decomposition of a matrix, and verify the reconstruction of the
    original matrix.
    ([Solution](Armadillo/svd.cpp))
  1. Write a program that solves a small system of linear equations using
    a linear algebra library.
    ([Solution](Eigen/solve_eqns.cpp))
  1. Use Boost Odeint to solve a system of ordinary differential
    equations, and write the trajectory to standard output.
    ([Solution](Boost/Math/Odeint/lorenz.cpp))
  1. Use Boost Math quadrature to compute the integral of a
    parameter-dependent function for a range of parameter values.
    ([Solution](Boost/Math/Quadratures/quad.cpp))


## <a name="pointers">Pointers</a>

  1. Write a program that illustrates the difference between a reference
    and a pointer to an `int`.  Print the addresses involved, and show
    how modifying the value through the reference and through the pointer
    affects the original variable.
    ([Solution](Pointers/pointers_vs_references.cpp))
  1. Write a program that illustrates the meaning of `int*`,
    `const int*`, `int* const`, and `const int* const`.  Show which
    assignments and modifications are allowed for each case.
    ([Solution](Pointers/const_and_pointers.cpp))
  1. Create a simple class hierarchy with a base class pointer that can
    refer to objects of derived classes.  Use virtual functions and
    `dynamic_cast` or `typeid` to illustrate the difference between
    runtime and compile-time type information.
    ([Solution](Pointers/runtime_vs_compile_time.cpp))
  1. Implement a binary tree using raw pointers for the child nodes.
    Build a small tree recursively and print it.  Ensure that all memory
    is released correctly.
    ([Solution](Pointers/Tree/tree.cpp))
  1. Reimplement the previous binary tree exercise using
    `std::unique_ptr` for the child nodes.
    ([Solution](Pointers/Tree/tree_uptr.cpp))
  1. Compare the previous two implementations with a version that uses
    shared ownership.  Build and print a tree using `std::shared_ptr`
    for the child nodes.
    ([Solution](Pointers/Tree/tree_sptr.cpp))
  1. Implement a persistent singly linked list using `std::shared_ptr`,
    and write a small program that demonstrates how multiple lists can
    share common tails safely.
    ([Solution](Pointers/SharedPointers/main.cpp))


## <a name="regexes">Strings and regular expressions (chapter 7)</a>

  1. Write a program that illustrates a number of basic `std::string`
    operations: concatenation, taking substrings, searching for a
    character, replacing text, and inserting text.
    ([Solution](Regexes/strings.cpp))
  1. Write a program that uses `std::regex_match` to test whether a
    collection of DNA-like strings matches a pattern.  Compare
    case-sensitive and case-insensitive matching.
    ([Solution](Regexes/case.cpp))
  1. Write a program that uses `std::regex_replace` to put quotes around
    every token in a comma-separated line of input.
    ([Solution](Regexes/simple_re_replace.cpp))
  1. Write a program that uses capturing groups and replacement to
    transform event names such as `run 15` into `run_15`.
    ([Solution](Regexes/reformat_events.cpp))
  1. Write a program that tokenizes text into words using a regular
    expression iterator, and counts how often each word occurs.
    ([Solution](Regexes/word_counter.cpp))
  1. Write a program that parses log lines containing timestamps and
    begin/end events using regular expressions.  It should match start
    and end events and compute the duration of each process.
    ([Solution](Regexes/processes.cpp))


## <a name="iostream">I/O streams (chapter 7)</a>

  1. Write a program that reads floating point numbers (represented as
    strings) from standard input, and when all are read, writes the sum
    to standard output.
  1. In the input file format, each line contains an arbitrary number
    of floating point values, separated by commas. In the output format,
    commas are replaced by tabs.  Write a program that takes an input
    file name and an output file name as command line arguments, and
    converts the input file to the new format, writing it to the output
    file.
  1. For the same input file format as above, compute the sum of the values
    of each row, and write a new CSV file, where the sum is the first entry
    in each row, followed by the values in the original file.
  1. The data for a person is represented by a structure with the first
    name, last name, and the person's age as fields. Overload the put-to
    and get-from operators to serialize and deserialize these data
    structures to text files.
