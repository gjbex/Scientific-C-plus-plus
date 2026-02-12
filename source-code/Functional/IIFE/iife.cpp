#include <functional>
#include <iostream>


int main() {
    // Immediately Invoked Function Expression (IIFE) in C++
    auto const result = [] {
        int a = 5;
        int b = 10;
        return a + b;
    }(); // Note the parentheses at the end to invoke the lambda immediately
    std::cout << "The result of the IIFE is: " << result << std::endl;

    // Another IIFE that uses the previous result and is invoked using std::invoke
    auto const value = std::invoke([&result] {
        return result * 2;
    });
    std::cout << "The result of the second IIFE is: " << value << std::endl;

    return 0;
}
