#include <iostream>
#include "iterable.h"
#include <span>
#include <vector>

int main() {
    static_assert(Iterable<std::vector<int>>, "vector<int> is iterable");
    static_assert(Iterable<std::span<float>>);
    static_assert(Iterable<float[]>);
    return 0;
}
