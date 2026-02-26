#include <iostream>
#include <regex>
#include <vector>


int main() {
    std::regex expr {R"([acgt]+)"};
    std::regex expr_icase(R"([acgt]+)", std::regex::icase);
    const std::vector<std::string> strs {"aagt", "abgt", "AAGT", "ABGT"};
    for (auto str: strs) {
        if (std::regex_match(str, expr))
            std::cout << "case sensitive: " << str << std::endl;
        if (std::regex_match(str, expr_icase))
            std::cout << "case insensitive: " << str << std::endl;
    }
    return 0;
}
