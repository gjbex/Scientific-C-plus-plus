# Include guards

Since C++ allows structs or functions to be defined only once, include guards need to
be add to header files to prevent multiple definitions. This is done by using preprocessor
directives to check if a unique identifier has been defined.


## What is it?

1. `src_with_guards`: directory  with source code that will build, as the header files
   have include guards.
1. `src_without_guards`: directory with source code that will not build, as the header files
   do not have include guards.
1. `CMakeLists.txt`: CMake file to build the versions.


## How to use it?

Configure the build system:

```bash
$ cmake  -S .  -B build
```

Build the version with include guards:

```bash
$ cmake --build build --target with_include_guards
```

Build the version without include guards:

```bash
$ cmake --build build --target without_include_guards
```
