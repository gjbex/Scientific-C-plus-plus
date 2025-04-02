#include <iostream>

void print_size(int data[]) {
    std::cout << "size in function: " << sizeof(data) << '\n';
}

int main() {
    int data[] {2, 3, 5, 7, 11};
    std::cout << "size in main: " << sizeof(data) << '\n';
    print_size(data);
    return 0;
}
