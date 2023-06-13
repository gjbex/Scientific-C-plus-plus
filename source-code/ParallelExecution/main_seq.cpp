#include <algorithm>
#include <execution>
#include <iostream>
#include "data.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "error: expecting array size\n";
        std::exit(1);
    }
    const size_t nr_items {std::stoul(argv[1])};
    auto data = create_data(nr_items);
    std::sort(std::execution::seq, data.begin(), data.end());
    std::cout << "first = " << data.front() << ", last = " << data.back() << "\n";
    return 0;
}
