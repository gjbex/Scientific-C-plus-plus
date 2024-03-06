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

template <Iterable T>
void print2(T t) {
    for (auto i : t) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    static_assert(Iterable<std::vector<int>>, "vector<int> is iterable");
    print(std::vector<int>{1, 2, 3, 4, 5});
    print2(std::vector<int>{1, 2, 3, 4, 5});
    static_assert(Iterable<std::span<float>>);
    float data[] = {1, 2, 3, 4, 5};
    std::span<float> s{data};
    print(s);
    print2(s);
    // static_assert(Iterable<float[]>); // error: float[] is not an iterable
    // print({1, 2, 3, 4, 5});           // float[] is not an iterable
    return 0;
}
