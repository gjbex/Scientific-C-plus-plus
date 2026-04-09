#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

struct Patient {
    std::string name;
    int priority;
};

struct PatientOrder {
    bool operator()(const Patient& lhs, const Patient& rhs) const {
        return lhs.priority < rhs.priority;
    }
};

std::string trim_leading_space(std::string text) {
    const auto pos = text.find_first_not_of(' ');
    if (pos == std::string::npos) {
        return "";
    }
    return text.substr(pos);
}

int main() {
    std::priority_queue<Patient, std::vector<Patient>, PatientOrder> waiting_room;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::istringstream stream(line);
        std::string command;
        stream >> command;

        if (command == "quit") {
            break;
        } else if (command == "arrive") {
            int priority {};
            if (!(stream >> priority)) {
                std::cerr << "arrive requires an integer priority and a name" << std::endl;
                continue;
            }
            std::string name;
            std::getline(stream, name);
            name = trim_leading_space(name);
            if (name.empty()) {
                std::cerr << "arrive requires an integer priority and a name" << std::endl;
                continue;
            }
            waiting_room.push(Patient {.name = name, .priority = priority});
        } else if (command == "treat") {
            if (waiting_room.empty()) {
                std::cerr << "no patients waiting" << std::endl;
                continue;
            }
            const auto next_patient = waiting_room.top();
            waiting_room.pop();
            std::cout << next_patient.name
                      << " (priority " << next_patient.priority << ")"
                      << std::endl;
        } else if (!command.empty()) {
            std::cerr << "unknown command: " << command << std::endl;
        }
    }

    return 0;
}
