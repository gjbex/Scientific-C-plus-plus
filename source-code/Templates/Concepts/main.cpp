#include <iostream>
#include "iterable.h"
#include <span>
#include <vector>

template <typename T>
requires Iterable<T> void print(T t) {
    for (auto i : t) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    static_assert(Iterable<std::vector<int>>, "vector<int> is iterable");
    print(std::vector<int>{1, 2, 3, 4, 5});
    static_assert(Iterable<std::span<float>>);
    static_assert(Iterable<float[]>);
    print({1, 2, 3, 4, 5});
    return 0;
}
