#include <iostream>
#include <vector>
#include "linked_list.h"

void print_list(const LinkedList& list) {
    list.apply([] (const ListElement& element) { std::cout << element.value() << " "; });
    std::cout << "\n";
}

int main() {
    std::vector<LinkedList> lists;
    lists.emplace_back();
    for (int value {12}; value < 17; value += 2) {
        LinkedList list{lists.back().prepend(value)};
        lists.push_back(list);
    }
    for (const auto& list: lists) {
        std::cout << "elements: ";
        print_list(list);
        std::cout << "counts:";
        for (const auto& count: list.use_counts()) {
            std::cout << " " << count;
        }
        std::cout << "\n";
        std::cout << "addresses:";
        for (const auto& address: list.addresses()) {
            std::cout << " " << address;
        }
        std::cout << "\n";
        std::cout << "---------------\n";
    }
    std::cout << "counts before insert creates a new list:";
    for (const auto& count: lists.back().use_counts()) {
        std::cout << " " << count;
    }
    std::cout << "\n";
    {
        // list will go out of scope at the end of the block,
        // so the use counts should go down again after the
        // block
        LinkedList list = lists.back().prepend(-13);
        std::cout << "counts in block where new list is in scope:";
        for (const auto& count: lists.back().use_counts()) {
            std::cout << " " << count;
        }
        std::cout << "\n";
    }
    std::cout << "counts after block when list is out of scope:";
    for (const auto& count: lists.back().use_counts()) {
        std::cout << " " << count;
    }
    std::cout << "\n";
    std::cout << "---------------\n";
    LinkedList append_list = lists.back().append(10);
    std::cout << "counts of append list:";
    for (const auto& count: append_list.use_counts()) {
        std::cout << " " << count;
    }
    std::cout << "\n";
    std::cout << "counts of original list:";
    for (const auto& count: lists.back().use_counts()) {
        std::cout << " " << count;
    }
    std::cout << "\n";
    std::cout << "---------------\n";
    LinkedList reversed_list = lists.back().reverse();
    std::cout << "reverse: ";
    print_list(reversed_list);
    return 0;
}
