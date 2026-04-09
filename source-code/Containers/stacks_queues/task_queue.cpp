#include <iostream>
#include <queue>
#include <sstream>
#include <string>

std::string trim_leading_space(std::string text) {
    const auto pos = text.find_first_not_of(' ');
    if (pos == std::string::npos) {
        return "";
    }
    return text.substr(pos);
}

int main() {
    std::queue<std::string> tasks;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream stream(line);
        std::string command;
        stream >> command;

        if (command == "quit") {
            break;
        } else if (command == "push") {
            std::string task;
            std::getline(stream, task);
            task = trim_leading_space(task);
            if (task.empty()) {
                std::cerr << "push requires a task description" << std::endl;
                continue;
            }
            tasks.push(task);
        } else if (command == "pop") {
            if (tasks.empty()) {
                std::cerr << "queue is empty" << std::endl;
                continue;
            }
            std::cout << tasks.front() << std::endl;
            tasks.pop();
        } else if (!command.empty()) {
            std::cerr << "unknown command: " << command << std::endl;
        }
    }

    return 0;
}
