#include <iostream>
#include "knapsack.h"

int main() {
    auto stuff = fill_stuff_random(15);
    for (const auto& item: stuff)
        std::cout << item << "\n";
    return 0;
}
