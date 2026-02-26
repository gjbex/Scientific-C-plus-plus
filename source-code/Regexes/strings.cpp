#include <iostream>


int main() {
    std::string str {"hello"};
    // concatenation
    str += " world!";
    std::cout << "'" << str << "', length: " << str.length() << std::endl;
    // substrings
    std::cout << "from 6: '" << str.substr(6) << "'" << std::endl;
    std::cout << "from 6, 5 chars: '" << str.substr(6, 5) << "'" << std::endl;
    auto pos = str.find("w");
    str[pos] = toupper(str[pos]);
    std::cout << str << std::endl;
    pos = 0;
    const std::string search_str {"o"};
    while ((pos = str.find(search_str, pos)) != std::string::npos) {
        std::cout << "found '" << search_str << "' at " << pos << std::endl;
        pos++;
    }
    str.replace(0, 1, "H");
    str.insert(6, "beautiful ");
    std::cout << str << std::endl;
    return 0;
}
