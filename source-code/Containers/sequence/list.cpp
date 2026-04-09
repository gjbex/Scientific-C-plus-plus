#include <algorithm>
#include <iostream>
#include <list>

void show_list(std::list<int> int_list) {
    for (const auto& value: int_list) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> int_list;
    for (int i = 0; i <= 20; i += 5) {
        int_list.push_back(i);
    }
    std::cout << "size 1: " << int_list.size() << std::endl;
    show_list(int_list);
    for (int i = 12; i >= 8; i--) {
        auto it = std::find_if(int_list.begin(), int_list.end(),
                [i] (int a) { return a >= i; });
        if (it != int_list.end()) {
            int_list.insert(it, i);
        } else {
            int_list.push_back(i);
        }
    }
    std::cout << "size 1: " << int_list.size() << std::endl;
    show_list(int_list);
    return 0;
}
