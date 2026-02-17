#include <iostream>
#include <expected>

enum class Error {
    InvalidArgument,
    Overflow,
};

using Result = std::expected<int, Error>;

Result fac(const int n) {
    if (n < 0) return std::unexpected(Error::InvalidArgument);
    if (n > 12) return std::unexpected(Error::Overflow); // 13! is too big for int
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "### error: expecting number as argument"
                  << std::endl;
        return 1;
    }
    int n = std::stoi(argv[1]);
    if (auto result = fac(n); result.has_value()) {
        std::cout << "fac(" << n << ") = " << *result << std::endl;
    } else if (result.error() == Error::InvalidArgument) {
        std::cerr << "### error: invalud argument for factorial function"
                  << std::endl;
        std::exit(1);
    } else if (result.error() == Error::Overflow) {
        std::cerr << "### error: factorial result is too big for int"
                  << std::endl;
        std::exit(2);
    }
    return 0;
}
