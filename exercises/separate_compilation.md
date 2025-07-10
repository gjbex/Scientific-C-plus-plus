 # Exercises: Separate Compilation & CMake

 These exercises will guide you through splitting C++ code across multiple translation units,
 organizing headers and sources, and building with CMake. Suitable for a 1–2 hour lab.

 ## Exercise 1: Splitting Functions into Header and Source

 1. Given a single-file program `main.cpp`:
    ```cpp
    #include <iostream>
    int add(int a, int b) {
        return a + b;
    }
    int multiply(int a, int b) {
        return a * b;
    }
    int main() {
        std::cout << "2+3=" << add(2,3) << "\n";
        std::cout << "2*3=" << multiply(2,3) << "\n";
        return 0;
    }
    ```
 2. Refactor into separate files:
    - `math_functions.h`: declarations of `add` and `multiply`, with include guards.
    - `math_functions.cpp`: definitions of `add` and `multiply`.
    - `main.cpp`: include `math_functions.h` and call the functions.
 3. Compile and link manually:
    ```bash
    g++ -c math_functions.cpp -o math_functions.o
    g++ -c main.cpp           -o main.o
    g++ math_functions.o main.o -o app
    ./app
    ```

 ## Exercise 2: Header Guards & Forward Declarations

 1. Explain why include guards (or `#pragma once`) are necessary.
 2. Create a header that is included twice in `main.cpp`, observe the error, then add guards to fix it.
 3. Demonstrate breaking a cyclic dependency using a forward declaration instead of including a full header.

 ## Exercise 3: Basic CMake Project

 1. Create this directory structure:
    ```
    project_root/
      CMakeLists.txt
      src/
        main.cpp
        math_functions.h
        math_functions.cpp
    ```
 2. Write `CMakeLists.txt`:
    ```cmake
    cmake_minimum_required(VERSION 3.10)
    project(MyApp)

    add_executable(app
        src/main.cpp
        src/math_functions.cpp
    )
    ```
 3. Build with CMake:
    ```bash
    mkdir build && cd build
    cmake ..
    cmake --build .
    ./app
    ```

 ## Exercise 4: Static Library with CMake

 1. Refactor the project to build a static library and an executable:
    - Library target `math` from `math_functions.cpp`/`.h`.
    - Executable target `app` that links to `math`.
 2. Update `CMakeLists.txt`:
    ```cmake
    add_library(math STATIC
        src/math_functions.cpp
    )
    target_include_directories(math PUBLIC src)

    add_executable(app src/main.cpp)
    target_link_libraries(app PRIVATE math)
    ```
 3. Rebuild in `build/` folder and verify that `app` runs correctly.

 ## Exercise 5: Splitting a Class into Header/Source

 1. Create a class `Point3D`:
    - `Point3D.h`: declarations, include guards.
    - `Point3D.cpp`: definitions.
 2. Required interface:
    ```cpp
    class Point3D {
    public:
        Point3D(double x, double y, double z);
        double distanceTo(const Point3D& other) const;
    private:
        double x_, y_, z_;
    };
    ```
 3. In `src/main.cpp`, include `Point3D.h`, construct two points, and print their distance.
 4. Add these files to your CMake targets (library or executable) and rebuild.

 ## Quiz Questions

 - What belongs in a header file vs. a source file?
 - What is a translation unit?
 - Why compile with `-c` before linking?
 - What does `target_include_directories` do in CMake?
 - Describe the difference between `add_library(... STATIC)` and `add_library(... SHARED)`.