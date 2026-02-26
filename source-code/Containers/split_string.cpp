#include <iostream>
#include <string>
#include <vector>


std::vector<std::string> split(const std::string& str, const std::string& delim);

int main(int argc, char *argv[]) {
    std::string delim = argc > 1 ? std::string(argv[1]) : std::string(",");
    while (std::cin) {
        std::string line;
        std::getline(std::cin, line);
        if (line.length() == 0)
            continue;
        std::vector<std::string> parts = split(line, delim);
        for (auto part: parts)
            std::cout << "'" << part << "'" << std::endl;
    }
    return 0;
}

std::vector<std::string> split(const std::string& str, const std::string& delim) {
    std::vector<std::string> parts;
    std::size_t pos = 0, old_pos = 0;
    while ((pos = str.find(delim, old_pos)) != std::string::npos) {
        parts.push_back(str.substr(old_pos, pos - old_pos));
        old_pos = pos + delim.length();
    }
    parts.push_back(str.substr(old_pos));
    return parts;
}
