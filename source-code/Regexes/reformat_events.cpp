#include <iostream>
#include <regex>


int main() {
    std::regex expr {R"((\w+)\s+(\d+))"};
    std::string line;
    while (std::getline(std::cin, line)) {
        std::string new_line = std::regex_replace(line, expr, "$1_$2");
        std::cout << new_line << std::endl;
    }
    return 0;
}
