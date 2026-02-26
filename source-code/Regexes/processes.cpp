#include <cstring>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <time.h>


std::time_t compute_duration(const std::string& start_str, const std::string& end_str) {
    struct tm start_tm, end_tm;
    std::memset(&start_tm, 0, sizeof(struct tm));
    std::memset(&end_tm, 0, sizeof(struct tm));
    if (!strptime(start_str.c_str(), "%Y-%m-%d %H:%M:%S", &start_tm)) {
        std::cerr << "# warning: string '" << start_str << "' is invalid"
             << std::endl;
        return 0;
    }
    if (!strptime(end_str.c_str(), "%Y-%m-%d %H:%M:%S", &end_tm)) {
        std::cerr << "# warning: string '" << start_str << "' is invalid"
             << std::endl;
        return 0;
    }
    std::time_t start_time = mktime(&start_tm);
    std::time_t end_time = mktime(&end_tm);
    return end_time - start_time;
}

int main() {
    std::string line;
    std::map<std::string, std::string> event_starts;
    std::map<std::string, std::time_t> event_durations;
    const std::string time_pat {R"((\d{4}-\d{2}-\d{2}\s+\d{2}:\d{2}:\d{2}))"};
    const std::string type_pat {R"(\[(\w+)\])"};
    const std::string event_pat {R"((begin|end)\s+(.+)\s*$)"};
    const std::string sep_pat {R"(\s+)"};
    std::regex pat(time_pat + ":" + sep_pat + type_pat + sep_pat + event_pat);
    while (std::getline(std::cin, line)) {
        std::smatch matches;
        if (std::regex_search(line, matches, pat)) {
            const std::string event_id = matches[4];
            if (matches[3] == "begin") {
                event_starts[event_id] = matches[1];
            } else if (matches[3] == "end") {
                if (event_starts.find(event_id) != event_starts.end()) {
                    auto duration = compute_duration(event_starts[event_id],
                                                     matches[1]);
                    event_durations[event_id] = duration;
                } else {
                    std::cerr << "# warning: end event for '" << event_id
                         << "' without start event" << std::endl;
                }
            }
        }
    }
    for (auto event: event_durations)
        std::cout << event.first << ": " << event.second << std::endl;
    return 0;
}
