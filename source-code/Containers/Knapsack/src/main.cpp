#include <iostream>
#include <vector>

#include "knapsack.h"

int main() {
    std::vector<int> items {1, 10, 100, 2, 20, 200, 3, 30, 300};
    Knapsack knapsack(100);
    for (const auto& item: items)
        if (knapsack.add(item))
            std::cout << "added " << item << "\n";
        else
            std::cout << "too heavy " << item << "\n";
    std::cout << knapsack << ": " << knapsack.weight() << std::endl;
    knapsack.remove(20);
    std::cout << knapsack << ": " << knapsack.weight() << std::endl;
    return 0;
}
