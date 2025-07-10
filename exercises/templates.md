 # Exercises: Basic Templates in C++

 These exercises illustrate the fundamental usage of templates in C++: function templates,
 class templates, template specializations, default template parameters, and template aliases.

 ## Exercise 1: Function Template `mySwap`

 1. Write a function template `mySwap` that swaps two values:
    ```cpp
    template<typename T>
    void mySwap(T& a, T& b) {
        T tmp = a;
        a = b;
        b = tmp;
    }
    ```
 2. In `main()`, test `mySwap` with:
    - `int` variables.
    - `double` variables.
    - `std::string` variables.
    Print before and after swapping.

 ## Exercise 2: Function Template `myMax` and Specialization

 1. Write a function template `myMax` that returns the larger of two values:
    ```cpp
    template<typename T>
    T myMax(const T& a, const T& b) {
        return (a < b) ? b : a;
    }
    ```
 2. Partially specialize or overload for `const char*` so that it compares C-strings by `std::strcmp`.
 3. Test `myMax` with `int`, `double`, `std::string`, and C-strings.

 ## Exercise 3: Class Template `Pair`

 1. Define a class template:
    ```cpp
    template<typename T1, typename T2>
    class Pair {
        T1 first_;
        T2 second_;
    public:
        Pair(const T1& a, const T2& b);
        const T1& first() const;
        const T2& second() const;
    };
    ```
 2. Implement constructor and accessors in a header-only fashion.
 3. In `main()`, create and print:
    - `Pair<int, double>`
    - `Pair<std::string, int>`

 ## Exercise 4: Class Template `Array`

 1. Define a fixed-size array template:
    ```cpp
    template<typename T, std::size_t N>
    class Array {
        T data_[N];
    public:
        constexpr std::size_t size() const;
        T& operator[](std::size_t i);
        const T& operator[](std::size_t i) const;
    };
    ```
 2. Implement `size()` and `operator[]` inline.
 3. Test `Array<int, 5>` by assigning and printing elements.

 ## Exercise 5: Default Template Parameters & Alias Templates

 1. Define a template class `Box` with a default type parameter:
    ```cpp
    template<typename T = int>
    class Box {
        T value_;
    public:
        Box(const T& v);
        const T& value() const;
    };
    ```
 2. Define template aliases:
    ```cpp
    using IntVector = std::vector<int>;
    template<typename K, typename V>
    using Map = std::map<K, V>;
    ```
 3. In `main()`, demonstrate:
    - `Box<>` (uses default `int`).
    - `Box<std::string>`.
    - `IntVector` and `Map<std::string, double>`.

 ## Exercise 6: Templates with Standard Algorithms

 1. Write a template function `printContainer` that takes any container with `begin()`/`end()` and prints its elements.
 2. In `main()`, create a `std::vector<double>`, sort it with `std::sort`, and print with `printContainer`.

 ## Quiz Questions

 - What is the difference between a template and a macro for generic code?
 - When is a template instantiated?
 - Why might you specialize or overload a function template?
 - How do default template parameters work?
 - What is a template alias, and how is it useful?