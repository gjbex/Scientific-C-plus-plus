#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using Digits = std::array<int, 4>;
using Numbers = std::vector<int>;

Digits number2digits(int number) {
    Digits digits;
    for (int i {0}; i < digits.size(); ++i) {
        digits[i] = number % 10;
        number /= 10;
    }
    return digits;
}

int digits2number(const Digits& digits) {
    int number {0};
    int factor {1};
    for (const auto& digit: digits) {
        number += factor*digit;
        factor *= 10;
    }
    return number;
}

void print_digits(const Digits& digits) {
    for (const auto& digit: digits) {
        std::cout << digit;
    }
    std::cout << "\n";
}

void print_numbers(const Numbers& numbers) {
    for (const auto& number: numbers) {
        std::cout << number << " ";
    }
    std::cout << "\n";
}

Numbers do_iterations(int number) {
    Numbers numbers;
    do {
        numbers.push_back( number);
        auto digits = number2digits(number);
        std::sort(digits.begin(), digits.end());
        int large = digits2number(digits);
        std::reverse(digits.begin(), digits.end());
        int small = digits2number(digits);
        number = large - small;
    } while (numbers.back() != number);
    return numbers;
}

int main(int argc, char* argv[]) {
    // handle input
    if (argc != 2) {
        std::cerr << "# error: requires number as argument\n";
        std::exit(1);
    }
    int number {std::stoi(argv[1])};
    print_numbers(do_iterations(number));
    return 0;
}
