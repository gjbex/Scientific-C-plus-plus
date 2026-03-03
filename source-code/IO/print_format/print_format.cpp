#include <print>
#include <vector>

int main() {
    const int i {5};
    const std::string str {"world"};
    std::println("value = {}, hello {}", i, str);
    std::vector<double> data {1.2, 2.3, 3.4, 4.5};
    std::println("data = {}", data);
    auto message = std::format("The value of pi is approximately {:.2f}", 3.14159);
    std::println("{}", message);
    return 0;
}
