#include <iostream>


int main() {
    int i {3};
    std::cout << "out of block: " << i << std::endl;
    {
        std::cout << "in block before declaration: " << i << std::endl;
        int i {5};
        std::cout << "in block after declaration: " << i <<  std::endl;
    }
    std::cout << "out of block before for: " << i << std::endl;
    for (int i = 10; i < 13; i++)
        std::cout << "in for: " << i << std::endl;
    std::cout << "out of block after for: " << i << std::endl;
    return 0;
}
