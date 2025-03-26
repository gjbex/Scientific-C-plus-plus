#include <iostream>

int fac(int n);

int main(int argc, char *argv[]) {
    if (argc < 1) {
        std::cerr << "#error: expecting one integer as argument" << std::endl;
        return 1;
    }
    int n {0};
    try {
        n = std::stoi(std::string(argv[1]));
    } catch (std::invalid_argument&) {
        std::cerr << "# error: argument can not be converted to an integer"
             << std::endl;
        return 3;
    }
    if (n < 0) {
        std::cerr << "# error: argument should be positive" << std::endl;
        return 4;
    }
    std::cout << fac(n) << std::endl;
    return 0;
}

int fac(int n) {
    int val {1};
    for (int i = 2; i <= n; i++)
        val *= i;
    return val;
}
