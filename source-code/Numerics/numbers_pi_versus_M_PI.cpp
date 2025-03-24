#include <chrono>
#include <cmath>
#include <iostream>
#include <numbers>

int main(int argc, char* argv[]) {
    float delta {0.01f};
    if (argc > 1) {
        delta = std::stof(argv[1]);
    }
    float sum {0.0f};
    auto start {std::chrono::high_resolution_clock::now()};
    for (float x = 0.0f; x < 1.0f; x += delta) {
        sum += M_PI*x;
    }
    auto end {std::chrono::high_resolution_clock::now()};
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Elapsed time for M_PI: " << elapsed_seconds.count() << "s\n";
    std::cout << "sum: " << sum << std::endl;
    sum = 0.0f;
    start = std::chrono::high_resolution_clock::now();
    for (float x = 0.0f; x < 1.0f; x += delta) {
        sum += std::numbers::pi_v<float>*x;
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Elapsed time for std::numbers::pi: " << elapsed_seconds.count() << "s\n";
    std::cout << "sum: " << sum << std::endl;
    return 0;
}
