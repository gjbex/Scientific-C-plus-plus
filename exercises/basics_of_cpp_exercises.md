# Basics of C++ Exercises

This set of exercises is designed to help you master the fundamental concepts of C++ covered in Section 1 of the slide deck, including variables, data types, I/O, expressions, branching, and loops.

## Exercises

1. **Hello, C++!**
   - Write, compile & run a program that prints `Hello, C++ world!` to the console.
   - Experiment: change the text, add a second line of output.

2. **Simple Data Types & I/O**
   - Declare one variable each of type `int`, `double`, and `char`.
   - Read values for each from `std::cin` and echo them back with `std::cout`.

3. **Arithmetic Operations**
   - Prompt the user for two numbers (ints or doubles) and print their sum, difference, product, and quotient.
   - Handle the “divide by zero” case gracefully.

4. **Fahrenheit ↔ Celsius Converter**
   - Read a temperature in Fahrenheit, compute and print Celsius:
     ```cpp
     C = (F - 32) * 5.0 / 9.0;
     ```
   - Then read a Celsius value and convert back to Fahrenheit.

5. **Even or Odd**
   - Read an integer and print whether it’s even or odd. (Hint: use `n % 2`.)

6. **Largest of Three Numbers**
   - Read three integers and use nested `if` statements (or logical operators) to find and print the largest.

7. **Sum of First N Natural Numbers**
   - Read an integer `N` and compute the sum `1 + 2 + … + N` in two ways:
     1. With a `for` loop.
     2. Using the formula `N * (N + 1) / 2`.
   - (Optional) Compare run times for large `N`.

8. **Multiplication Table**
   - Read an integer `n` and print its multiplication table from `n × 1` to `n × 12` using a loop.

9. **Factorial Calculation**
   - Read `N` (e.g., up to 20) and compute `N!` using a `for` or `while` loop.
   - Consider integer overflow — which data type can hold up to `20!`?

10. **Prime Number Check**
    - Read an integer and test whether it’s prime (trial division up to √n).
    - If it’s composite, print all of its divisors.

11. **Fibonacci Sequence (Iterative)**
    - Read `N` and print the first `N` Fibonacci numbers using a loop and two temporaries only (no recursion).

12. **Quick Debugging Challenge**
    - The following snippet contains several compilation errors. Identify and fix them.

```cpp
// buggy.cpp
#include <iostream>

int main() {
    int x = 10
    if (x = 5) {
        std::cout << "x is five" << std::endl;
    } else {
        std::cout << "x is not five" << std::endl;
    }
    return 0;
}
```
    - After fixing, compile and run the program. For each error, explain what was wrong and how you fixed it.

---

## Optional Stretch Goals

- Refactor the **Factorial** and **Fibonacci** computations into separate functions.
- Store and print results in a `std::vector` or array.
- Overload a simple `add` function for `int` vs. `double` arguments.

*Happy coding!*  
