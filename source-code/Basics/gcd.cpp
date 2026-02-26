#include <iostream>


int gcd(int x, int y);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "#error: expecting two integers as arguments" << std::endl;
        return 1;
    }
    int x = std::stoi(std::string(argv[1]));
    int y = std::stoi(std::string(argv[2]));
    std::cout << gcd(x, y) << std::endl;
    return 0;
}

int gcd(int x, int y) {
    while (x != y)
        if (x > y)
            x -= y;
        else
            y -= x;
    return x;
}
