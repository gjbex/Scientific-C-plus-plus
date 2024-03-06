#include <expected>
#include <iostream>
#include <limits>
#include <stdexcept>

using ErrorResult = std::string;
using ParseResult = std::string;

std::expected<ParseResult, ErrorResult> parse_arguments(int argc, char* argv[]) {
    std::string app_name {argv[0]};
    if (argc != 2) {
        return std::unexpected(app_name + " takes 1 argument");
    }
    return ErrorResult(argv[1]);
}

using ValidateResult = int;

std::expected<ValidateResult, ErrorResult> validate_arguments(const ParseResult& arg) {
    try {
        return ValidateResult(std::stoi(arg));
    } catch (const std::invalid_argument& e) {
        return std::unexpected("can not convert '" + arg + "' to an integer");
    } catch (const std::out_of_range& e) {
        return std::unexpected(arg + " is too large to convert to an integer");
    }
}

using FunctionResult = int;

std::expected<FunctionResult, ErrorResult>  fac(ValidateResult n) {
    if (n < 0) {
        return std::unexpected("fac argument " + std::to_string(n) + ", must be positive");
    } else {
        const int max_int {std::numeric_limits<int>::max()};
        int result = 1;
        for (int i = 2; i <= n; i++) {
            if (result < max_int/i) {
                result *= i;
            } else {
                return std::unexpected("fac argument " + std::to_string(n) + " causes overflow");
            }
        }
        return FunctionResult(result);
    }
}

std::expected<FunctionResult, ErrorResult> show_result(FunctionResult result) {
    std::cout << result << std::endl;
    return result;
}

std::expected<FunctionResult, ErrorResult> show_error(const ErrorResult& error) {
    std::cerr << "# error: " << error << std::endl;
    return std::unexpected(error);
}

int main(int argc, char *argv[]) {
    auto result = parse_arguments(argc, argv)
        .and_then(validate_arguments)
        .and_then(fac)
        .and_then(show_result)
        .or_else(show_error) ;
    if (result) {
        return 0;
    } else {
        return 1;
    }
    return 0;
}
