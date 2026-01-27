#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>

namespace rv = std::ranges::views;

struct Person {
    std::string name;
    int age;
};

int main() {
    std::vector<Person> people = {
        {"Charlie", 30},
        {"Bob", 25},
        {"Alice", 35}
    };

    for (const auto& person : people) {
        std::cout << person.name << ": " << person.age << '\n';
    }

    std::cout << "----" << std::endl;

    std::cout << "Sorted by name:" << std::endl;
    std::ranges::sort(people, std::less{}, &Person::name);
    for (const auto& person : people) {
        std::cout << person.name << std::endl;
    }

    std::cout << "----" << std::endl;
    std::cout << "Sorted by age:" << std::endl;
    std::ranges::sort(people, std::less{}, &Person::age);
    for (const auto& person : people) {
        std::cout << person.name << std::endl;
    }
    return 0;
}
