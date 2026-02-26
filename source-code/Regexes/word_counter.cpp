#include <iostream>
#include <unordered_map>
#include <regex>


int main() {
    std::string line;
    std::regex pat {R"((\w+))"};
    std::unordered_map<std::string, int> counter;
    while (std::getline(std::cin, line)) {
        for (std::sregex_iterator token(line.begin(), line.end(), pat);
                token != std::sregex_iterator {}; token++) {
            std::string word = (*token)[1];
            if (counter.find(word) == counter.end())
                counter[word] = 0;
            counter[word]++;
        }
    }
    for (auto c: counter)
        std::cout << c.first << ": " << c.second << std::endl;
    return 0;
}
