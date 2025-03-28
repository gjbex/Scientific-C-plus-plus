#include <algorithm>
#include <iostream>

int main() {
    std::string str;
    std::string line;
    while (std::getline(std::cin, line))
        str += line + "\n";
    const std::string target {"words"};
    auto start {str.cbegin()};
    auto it {str.cbegin()};
    while ((it = std::search(start, str.cend(),
                    target.cbegin(), target.cend())) != str.cend()) {
        std::cout << "found at " << it - str.cbegin() << std::endl;
        start = it + 1;
    }
    return 0;
}
