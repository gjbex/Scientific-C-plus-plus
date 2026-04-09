#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, std::size_t> counts;
    std::string word;
    while (std::cin >> word) {
        counts[word]++;
    }

    if (counts.empty()) {
        std::cerr << "no words provided" << std::endl;
        return 1;
    }

    auto best = counts.cbegin();
    for (auto it = std::next(counts.cbegin()); it != counts.cend(); ++it) {
        if (it->second > best->second ||
            (it->second == best->second && it->first < best->first)) {
            best = it;
        }
    }

    std::cout << best->first << ": " << best->second << std::endl;
    return 0;
}
