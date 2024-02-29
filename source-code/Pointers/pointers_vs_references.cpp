#include <iostream>

int main() {
    int a {5};
    int& b {a};
    std::cout << "&a = " << &a << ", &b = " << &b << "\n";
    std::cout << "a = " << a << ", b = " << b << "\n";
    b = 3;
    std::cout << "a = " << a << ", b = " << b << " after b = 3\n";
    int* p {&a};
    std::cout << "&a = " << &a << ", p = " << p << ", &p = " << &p << "\n";
    std::cout << "a = " << a << ", *p = " << *p << "\n";
    *p = 9;
    std::cout << "a = " << a << ", *p = " << *p << " after *p = 9\n";
    return 0;
}
