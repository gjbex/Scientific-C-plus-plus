#include <iostream>

struct A {
    int value_;
    A() = default;
    explicit A(int value) : value_ {value} {}
};

struct B {
    int value_;
    B() = default;
    B(int value) : value_ {value} {}
};

void print_A(const A& a) {
    std::cout << "A: " << a.value_ << '\n';
}

void print_B(const B& b) {
    std::cout << "B: " << b.value_ << '\n';
}

int main() {
    print_A(A(3));
    print_B(B(3));
    // This would not compile
    // print_A(3);
    print_B(3);
    return 0;
}
