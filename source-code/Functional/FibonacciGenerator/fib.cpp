#include <generator>
#include <iostream>
#include <utility>

std::generator<unsigned long> fibonacci() {
    unsigned long a = 1, b = 1;
    while (true) {
        co_yield a;
        a = std::exchange(b, a + b);
    }
}

int main() {
    for (auto i : fibonacci()) {
        if (i > 100) break;
        std::cout << i << ' ';
    }
    std::cout << '\n';
    return 0;
}
