#include <iostream>
#include <span>

int main(int argc, char* argv[]) {
    std::cout << "Number of arguments: " << argc << std::endl;

    std::span<char*> args(argv, static_cast<std::size_t>(argc));
    for (const auto& arg : args) {
        std::cout << "Argument: " << arg << std::endl;
    }

    return 0;
}
