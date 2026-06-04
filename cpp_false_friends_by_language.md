# C++ false friends by programming background

This note highlights common stumbling blocks for researchers learning C++ after using C, Fortran, Python, R, or MATLAB.  The goal is not to compare languages in general, but to point out places where familiar habits can lead to incorrect, inefficient, or unnecessarily complicated C++.

The examples assume modern C++: prefer the standard library, value types, RAII, `std::vector`, `std::string`, algorithms, and clear ownership over low-level manual resource management.

## General C++ habits that help everyone

- C++ distinguishes strongly between values, references, pointers, object lifetime, and ownership.  Many mistakes come from treating these as interchangeable.
- Prefer standard library types over raw arrays and manual allocation: use `std::vector`, `std::array`, `std::string`, `std::unique_ptr`, and `std::shared_ptr` when ownership is shared.
- Avoid writing `new` and `delete` in ordinary application code.  Resource management should usually be automatic.
- Check indexing carefully: C++ uses zero-based indexing and half-open ranges, such as `[begin, end)`.
- Integer division truncates: `1 / 2` is `0`, while `1.0 / 2` is `0.5`.
- Uninitialized local variables have indeterminate values.  Always initialize.
- `const` is useful and common.  Use it to express that a value or object should not be modified.
- Compilation errors can be verbose.  Read from the first relevant error in your own code, not necessarily from the last line of the diagnostic.
- Headers are interfaces.  Put declarations in headers and definitions in source files unless there is a good reason not to, such as templates or small inline functions.
- Performance-sensitive C++ code is often about data layout, allocation patterns, copies, and cache behavior, not just about choosing the right loop.

## From C

C programmers often recognize much of C++ syntax, which can be misleading.  C++ is not just C with classes.

### False friends

- **Manual memory management as the default**: In C, explicit allocation is routine.  In C++, prefer automatic storage, containers, and RAII.  A `std::vector<double>` is usually a better starting point than `malloc`, `calloc`, or `new[]`.
- **Raw arrays as normal containers**: C arrays decay to pointers and carry no size.  In C++, use `std::array<T, N>` for fixed size and `std::vector<T>` for dynamic size.
- **Pointers for every kind of indirection**: C++ has references, smart pointers, iterators, views, and spans.  A pointer should often mean "nullable non-owning access", not "generic access to something".
- **Structs as passive records only**: In C++, `struct` and `class` are almost the same; the main difference is default visibility.  It is normal for a `struct` to have constructors or member functions when that improves invariants.
- **C-style casts**: Avoid casts such as `(double)x`.  Prefer no cast when possible, or use the explicit C++ casts: `static_cast`, `const_cast`, `reinterpret_cast`, and `dynamic_cast`.
- **`printf`-style formatting**: Type mismatches in format strings are easy to miss.  Prefer streams, `std::format` where available, or a project-approved formatting library.
- **Preprocessor-heavy programming**: Prefer `constexpr`, `const`, templates, inline functions, namespaces, and typed enums over macros where possible.
- **Ignoring constructors and destructors**: C++ objects can acquire and release resources automatically.  This is central to exception safety and clean code.
- **Assuming `memcpy` is safe for objects**: Many C++ types are not safe to copy byte-by-byte.  Use normal copy/move operations unless the type is explicitly trivial and the operation is justified.

### Practical advice

Write C++ as C++: start with containers, functions, classes with clear invariants, and standard algorithms.  Drop to raw pointers, manual allocation, or byte-level operations only when the need is concrete.

## From Fortran

Fortran programmers often bring strong numerical-programming habits.  The main surprises are memory layout, indexing, and explicitness around data movement.

### False friends

- **Array indexing**: Fortran arrays are commonly one-based; C++ arrays and containers are zero-based.
- **Memory layout**: Fortran arrays are column-major; C++ multidimensional arrays and most C++ libraries use row-major layout by default.  This affects interoperability and loop order.
- **Array slicing**: Fortran has rich built-in array slicing.  C++ containers do not automatically provide the same semantics.  Use library views, spans, ranges, or domain-specific libraries where appropriate.
- **Whole-array operations**: Expressions such as `a = b + c` are natural in Fortran.  In standard C++, this usually requires loops, algorithms, or a numerical library.
- **Pass-by-reference assumptions**: Fortran argument passing can feel reference-like.  C++ makes this explicit with `T&`, `const T&`, pointers, or values.
- **Implicit typing habits**: Fortran has historical implicit typing rules, even if modern Fortran code avoids them.  C++ requires declarations but `auto` can hide important types if overused without care.
- **Assumed-shape arrays**: C++ functions do not automatically know array dimensions when passed raw arrays or pointers.  Prefer containers or pass dimensions explicitly.
- **Compilation model**: C++ headers, declarations, templates, and separate translation units behave differently from Fortran modules.
- **Numerical libraries**: C++ has no built-in BLAS-like array language.  Use established libraries for dense linear algebra, sparse matrices, FFTs, or PDE solvers.

### Practical advice

Be explicit about shape, layout, and ownership.  For scientific code, decide early which array or linear algebra library the project uses, and do not reinvent multidimensional array handling unless that is the learning objective.

## From Python

Python programmers often expect dynamic behavior, automatic memory management, and quick feedback.  C++ asks for more up-front precision, but gives much more control over layout and performance.

### False friends

- **Names versus objects**: Python variables are names bound to objects.  C++ variables are objects, references, or pointers with specific lifetimes and types.
- **Assignment**: In Python, assignment usually rebinds a name.  In C++, assignment usually copies or moves a value into an existing object.
- **Mutability expectations**: C++ has `const`, mutable and immutable access, value copies, references, and views.  Whether a function can modify an object is part of the type.
- **Dynamic typing**: C++ type errors happen at compile time.  This can feel strict, but it prevents many runtime failures.
- **Duck typing**: C++ generic code uses templates, concepts, overloads, and compile-time checks.  Error messages may be unfamiliar.
- **Lists versus vectors**: Python lists are heterogeneous references to objects.  `std::vector<T>` stores homogeneous values contiguously.
- **Slicing**: Python slicing commonly creates a new list or a view-like object depending on the library.  C++ slicing is not built into `std::vector`; use iterators, spans, ranges, or library views.
- **Automatic big integers**: Python integers grow arbitrarily large.  C++ integer types have fixed ranges and can overflow.
- **Exceptions and cleanup**: C++ uses exceptions too, but deterministic destructors make cleanup different.  RAII is more important than `finally`-style habits.
- **Interactivity**: C++ is usually compiled.  Faster iteration comes from small examples, good tests, and incremental builds, not from changing code inside a REPL.

### Practical advice

Think of C++ code as specifying data representation and allowed operations.  Use the compiler as feedback, and be deliberate about copies: passing a large object by value is different from passing it by `const&`.

## From R

R programmers often come from a vectorized, data-analysis-oriented environment.  C++ is less forgiving about types, sizes, missing values, and implicit recycling.

### False friends

- **Vectorization as the default**: R encourages whole-vector operations.  Standard C++ usually requires explicit loops, algorithms, or numerical libraries.
- **One-based indexing**: R is one-based; C++ is zero-based.
- **Recycling rules**: R may recycle shorter vectors in operations.  C++ containers do not do this.  Size mismatches must be handled explicitly.
- **Missing values**: R has `NA`, `NaN`, and related conventions.  C++ has no universal missing-value marker.  Use `std::optional`, sentinel values, masks, or library-specific missing-data support.
- **Copy-on-modify intuition**: R often hides copies.  In C++, copies, moves, references, and views are explicit and can affect both correctness and performance.
- **Data frames**: Standard C++ has no built-in data frame.  Choose a library or model the data explicitly.
- **Type coercion**: R often coerces types automatically.  C++ conversions are more explicit, and narrowing conversions can be dangerous.
- **Factors and categorical data**: C++ has no direct equivalent to R factors.  Use enums, strings, integer codes, or a suitable library depending on the task.
- **Formula interfaces**: R packages often accept compact statistical formulas.  C++ scientific code usually expresses models through functions, classes, or library APIs.

### Practical advice

Make data shape, type, and missing-value policy explicit.  When translating R-style analysis to C++, decide whether you are writing a numerical kernel, a data-processing pipeline, or a statistical model interface; each suggests different abstractions.

## From MATLAB

MATLAB programmers often expect matrix-first syntax and interactive numerical workflows.  C++ can support similar work, but usually through libraries rather than the core language.

### False friends

- **One-based indexing**: MATLAB is one-based; C++ is zero-based.
- **Matrix as the default data type**: MATLAB treats arrays as central.  C++ has scalars, arrays, vectors, classes, and library matrix types; there is no built-in general matrix type.
- **Column-major layout**: MATLAB arrays are column-major.  C++ containers and many C++ libraries are row-major by default, although some libraries let you choose.
- **Element-wise versus matrix operations**: MATLAB distinguishes `*` from `.*`.  In C++, operator meaning depends on the type and library.  Do not assume syntax maps directly.
- **Implicit expansion and broadcasting**: MATLAB supports powerful broadcasting.  Standard C++ does not.  Libraries may provide similar behavior, but rules differ.
- **Growing arrays in loops**: MATLAB users learn that repeated growth can be slow, but MATLAB often still makes it convenient.  In C++, repeated reallocation is also costly; use `reserve`, known sizes, or suitable builders.
- **Interactive workspace habits**: C++ programs need clear initialization, input/output, and testable functions.  There is no persistent workspace unless you build one.
- **Scripts versus functions**: MATLAB scripts can share workspace state.  C++ code should make dependencies explicit through function arguments, objects, and return values.
- **Plotting and visualization**: C++ has no standard plotting library.  For research workflows, it may be better to compute in C++ and visualize with Python, R, MATLAB, or a dedicated tool.

### Practical advice

Pick a numerical library before translating MATLAB code directly.  A good C++ translation usually preserves the mathematical intent, not the exact MATLAB syntax.

## Cross-language traps in scientific code

### Numeric types and precision

- Be explicit about `float`, `double`, integer types, and literals.
- `1 / 2`, `1.0 / 2.0`, and `static_cast<double>(i) / n` are different.
- Signed and unsigned integer comparisons can surprise you.
- Floating-point equality is usually the wrong test for computed values; use tolerances appropriate to the problem.

### Copies, references, and performance

- Passing `std::vector<double>` by value copies the vector unless it is moved.
- Passing by `const std::vector<double>&` avoids copying and promises not to modify.
- Returning containers by value is often fine in modern C++ because moves and copy elision are effective.
- Views are useful but require lifetime discipline: a view must not outlive the data it refers to.

### Ownership and lifetime

- A reference or pointer to a local variable becomes invalid after the variable goes out of scope.
- Do not return references to local variables.
- Prefer owning objects with automatic lifetime.
- Use smart pointers only when ordinary values and containers do not express the ownership well.

### Libraries and interoperability

- Many scientific C++ projects depend on external libraries.  Learn the build system, include paths, linking, and compiler options early.
- Interoperability with C, Fortran, Python, R, or MATLAB can be valuable, but data layout, ownership, and calling conventions must be handled carefully.
- For HPC code, understand whether the project uses MPI, OpenMP, CUDA, HIP, SYCL, Kokkos, RAJA, or another portability layer before designing abstractions.

## Summary table

| Background | Most likely false friend | C++ habit to develop |
| --- | --- | --- |
| C | Treating C++ as C with extra syntax | Use RAII, standard containers, references, and typed abstractions |
| Fortran | Assuming familiar array layout and slicing | Be explicit about shape, layout, indexing, and library choices |
| Python | Expecting dynamic names and automatic behavior | Understand values, types, lifetimes, copies, and references |
| R | Expecting vectorized data-frame semantics | Make sizes, missing values, and data representation explicit |
| MATLAB | Expecting matrix-first built-in syntax | Choose numerical libraries and translate mathematical intent |

## Teaching tip

When participants ask "what is the C++ equivalent of this feature?", first identify whether they mean syntax, semantics, performance behavior, or workflow.  The best C++ answer is often not a direct translation, but a design that makes data ownership, types, and operations explicit.
