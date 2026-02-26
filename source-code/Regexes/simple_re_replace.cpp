#include <iostream>
#include <regex>


int main() {
    const std::string str {"2.5, -1.3, alpha"};
    std::regex expr {R"(([^ ,]+))"};
    const std::string new_str = std::regex_replace(str, expr, "'$1'");
    std::cout << new_str << std::endl;
    return 0;
}
