#include <iostream>
#include <vector>

#include "buffer.h"

int main() {
    CircularBuffer<int> buffer(5);
    std::cout << buffer << "\n";
    for (int i {5}; i < 8; ++i) {
        buffer.push_back(i);
    }
    std::cout << buffer << "\n";
    while (!buffer.empty()) {
        std::cout << "popped " << buffer.pop_front() << "\n";
    }
    std::cout << buffer << "\n";
    for (int i {1}; i <= 7; ++i) {
        buffer.push_back(i);
    }
    std::cout << buffer << "\n";
    while (!buffer.empty()) {
        std::cout << "popped " << buffer.pop_front() << "\n";
    }
    std::cout << buffer << "\n";
    for (int i {2}; i < 5; ++i) {
        buffer.push_back(i);
    }
    std::cout << "buffer:\n" << buffer << "\n";

    std::cout << "---- copy constructor ----\n";
    CircularBuffer<int> buffer2(buffer);
    std::cout << "buffer2:\n" << buffer2 << "\n";
    buffer2.push_back(-13);
    std::cout << "buffer:\n" << buffer << "\n";
    std::cout << "buffer2:\n" << buffer2 << "\n";

    std::cout << "---- move constructor ----\n";
    std::vector<CircularBuffer<int>> v;
    v.reserve(2);
    v.push_back(CircularBuffer<int>(5));
    v.push_back(CircularBuffer<int>(3));
    for (const auto& buffer: v) {
        std::cout << buffer << "\n";
    }

    std::cout << "---- copy assignment ----\n";
    CircularBuffer<int> buffer3(29);
    buffer3 = buffer2;
    std::cout << "buffer2:\n" << buffer2 << "\n";
    std::cout << "buffer3:\n" << buffer3 << "\n";
    buffer3.push_back(17);
    std::cout << "buffer2:\n" << buffer2 << "\n";
    std::cout << "buffer3:\n" << buffer3 << "\n";

    std::cout << "---- move assignment ----\n";
    CircularBuffer<int> buffer4(10);
    buffer4 = std::move(buffer2);
    std::cout << "buffer2:\n" << buffer2 << "\n";
    std::cout << "buffer4:\n" << buffer4 << "\n";
    std::cout << "popped " << buffer4.pop_front() << "\n";
    std::cout << "buffer2:\n" << buffer2 << "\n";
    std::cout << "buffer4:\n" << buffer4 << "\n";
    return 0;
}
