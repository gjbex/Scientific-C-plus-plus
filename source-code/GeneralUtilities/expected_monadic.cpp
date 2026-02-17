#include <iostream>
#include <expected>

enum class Error {
    ParseError,
    InvalidArgument,
    Overflow,
};


std::expected<int, Error> parse_int(const std::string &s) {
    try {
        return std::stoi(s);
    } catch (const std::invalid_argument &) {
        return std::unexpected(Error::ParseError);
    } catch (const std::out_of_range &) {
        return std::unexpected(Error::Overflow);
    }
}

std::expected<int, Error> require_positive(int n) {
    if (n < 0) return std::unexpected(Error::InvalidArgument);
    return n;
}

std::expected<int, Error> within_range(int n) {
    if (n > 13) return std::unexpected(Error::Overflow);
    return n;
}

std::expected<int, Error> fac(const int n) {
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
    std::string input = argv[1];
    auto result = parse_int(input)
        .and_then(require_positive)
        .and_then(within_range)
        .and_then(fac)
        .or_else([](Error e) -> std::expected<int, Error> {
            switch (e) {
            case Error::ParseError:
                std::cerr << "### error: invalid number format"
                          << std::endl;
                break;
            case Error::InvalidArgument:
                std::cerr << "### error: expecting positive number"
                          << std::endl;
                break;
            case Error::Overflow:
                std::cerr << "### error: number too large"
                          << std::endl;
                break;
            }
            return std::unexpected(e);
        });
    if (result) {
        std::cout << "factorial: " << result.value() << std::endl;
    }
    return 0;
}
