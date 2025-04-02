#include <iostream>

#include "persistent_binary_tree.h"

int main() {
    PersistentBinaryTree<int> tree;
    if (tree.is_empty()) {
        std::cout << "empty tree\n";
    }
    if (!tree.has_left()) {
        std::cout << "no left child\n";
    }
    int value {5};
    tree.search(value);
    /*
    while (std::cin >> value) {
        tree.insert(value);
    }
    */
    // std::cout << tree << "\n";
    return 0;
}
