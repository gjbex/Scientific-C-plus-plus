 # Exercises: User-Defined Types in C++

 This exercise set provides hands-on practice with user-defined types in C++
 (structs, classes, constructors/destructors, access control, and simple operator
 overloading). It is suitable for a 1–2 hour lab session with bachelor-level
 science students (physics, chemistry) who have little programming experience.

 ## Exercise 1: 3-D Point struct & free functions

 1. Define a `struct`:
    ```cpp
    struct Point3D {
        double x, y, z;
    };
    ```
 2. Write a free (non-member) function that computes the Euclidean distance between two points:
    ```cpp
    double distance(const Point3D& A, const Point3D& B);
    ```
 3. In `main()`, read two points from standard input and print their separation.

 ## Exercise 2: Simple Vector class with member functions

 1. Turn `Point3D` into a `class Vector3D` that:
    - Stores `x, y, z` as private members.
    - Provides:
      - A default constructor (initializes to the zero vector).
      - A 3-argument constructor.
      - Public member functions:
        ```cpp
        double norm() const;    // returns the vector length
        void normalize();       // scales the vector to length 1 (if non-zero)
        std::string to_string() const; // (optional) returns a string representation
        ```
 2. In `main()`, demonstrate constructing, normalizing, and printing several vectors.

 ## Exercise 3: Operator overloading for Vector3D

 1. Add overloads for:
    ```cpp
    Vector3D operator+(const Vector3D& a, const Vector3D& b);
    Vector3D operator-(const Vector3D& a, const Vector3D& b);
    double   operator*(const Vector3D& a, const Vector3D& b); // dot product
    ```
 2. In `main()`, write tests that add, subtract, and dot two vectors, printing the results.

 ## Exercise 4: Encapsulation & Unit-Safe Physical Quantity

 1. Create a class `Distance` that stores a single private member `double meters_`.
 2. Provide:
    - An explicit constructor: `explicit Distance(double m);`
    - A conversion member: `double to_km() const;`
    - An addition operator: `Distance operator+(const Distance&) const;`
 3. In `main()`, read two distances (in meters), sum them, and print both in meters and kilometers.

 ## Exercise 5: Enum & `using`

 1. Define an `enum class Element { H, He, Li, Be, B, C };`.
 2. Write a free function:
    ```cpp
    std::string to_string(Element);
    ```
 3. Use a type alias:
    ```cpp
    using AtomicNumber = int;

    struct Atom {
        Element type;
        AtomicNumber Z;
        double mass;
    };
    ```
 4. In `main()`, create an `std::vector<Atom>` for the first five elements and print each atom’s name, atomic number, and mass.

## Exercise 6: Complex-Number Class with I/O

 1. Write a `class Complex` with private members `double re_, im_;` and:
    - Constructors.
    - Accessors: `double real() const;`, `double imag() const;`.
 2. Overload:
    ```cpp
    Complex operator+(const Complex&, const Complex&);
    Complex operator*(const Complex&, const Complex&);
    std::ostream& operator<<(std::ostream&, const Complex&);
    std::istream& operator>>(std::istream&, Complex&);
    ```
 3. In `main()`, read two complex numbers (format: `a+bi`), compute `(a+b)*(c+d)`, and print the result.

 ## Quiz Questions

- What is the default access level for members of a `struct` vs. a `class`?
- Why might you choose a free (non-member) function over a member function?
- What does the `explicit` keyword prevent?
- When would you prefer `enum class` over a plain `enum`?