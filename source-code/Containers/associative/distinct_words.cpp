#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::unordered_set<std::string> words;
    std::string word;
    while (std::cin >> word) {
        words.insert(word);
    }

    std::cout << "number of distinct words: " << words.size() << std::endl;
    return 0;
}
