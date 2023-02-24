#include <algorithm>
#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

bool is_divisible_by(size_t m, size_t n) {
    return m % n == 0;
}

bool is_prime(size_t n) {
    if (n == 0 || n == 1) {
        return false;
    } else {
        const double epsilon {1.0e-5};
        for (size_t divisor = 2; divisor < sqrt(n) + epsilon; ++divisor) {
            if (is_divisible_by(n, divisor)) {
                return false;
            }
        }
        return true;
    }
}

using Sieve = std::vector<bool>;

Sieve create_sieve(int max_number) {
    Sieve sieve(max_number + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for (size_t number = 2; number < sieve.size(); ++number) {
        if (sieve[number]) {
            for (size_t multiple = 2*number; multiple < sieve.size(); multiple += number) {
                sieve[multiple] = false;
            }
        }
    }
    return sieve;
}

int verify_sieve(const Sieve& sieve) {
    int nr_errors {0};
    for (size_t number = 0; number < sieve.size(); ++number) {
        if (bool target = is_prime(number); sieve[number] != target) {
            std::cerr << "# error: for " << number
                << " expect " << target
                << " got " << sieve[number] << "\n";
            ++nr_errors;
        }
    }
    return nr_errors;
}

using my_time_t = std::chrono::microseconds;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "# error: expecting number as argument\n";
        std::exit(1);
    }
    int max_number {std::stoi(argv[1])};
    auto start_time = std::chrono::steady_clock::now();
    Sieve sieve = create_sieve(max_number);
    auto end_time = std::chrono::steady_clock::now();
    auto delta_time = std::chrono::duration_cast<my_time_t>(end_time - start_time);
    std::cout << "construction took " << delta_time.count() << " us\n";
    /*
    for (int number = 1; number < sieve.size(); ++number) {
        if (sieve[number]) {
            std::cout << number << " is prime\n";
        } else {
            std::cout << number << " is not prime\n";
        }
    }
    */
    start_time = std::chrono::steady_clock::now();
    int nr_errors {verify_sieve(sieve)};
    end_time = std::chrono::steady_clock::now();
    delta_time = std::chrono::duration_cast<my_time_t>(end_time - start_time);
    std::cout << "verification took " << delta_time.count() << " us\n";
    std::cout << nr_errors << " errors\n";
    if (nr_errors > 0) {
        std::exit(2);
    }
    return 0;
}
