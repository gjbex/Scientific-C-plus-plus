#include <boost/bimap/bimap.hpp>
#include <iostream>
#include <vector>

namespace bm = boost::bimaps;

using Bimap = bm::bimap<bm::set_of<std::string>, bm::set_of<int>>;
using Value_type = Bimap::value_type;

int main() {
    std::vector<std::string> names {"dave", "bob", "alice", "carol" , "bob", "carol"};
    Bimap map;
    
    int i {1};
    for (const auto& name: names) {
        map.insert(Value_type(name, i++));
    }
    for (auto it = map.right.begin(); it != map.right.end(); ++it) {
        std::cout << it->first << " -> " << it->second << "\n";
    }
    for (auto it = map.left.begin(); it != map.left.end(); ++it) {
        std::cout << it->first << " -> " << it->second << "\n";
    }
    std::cout << "bob is at " << map.left.at("bob") << "\n";
    std::cout << "3 is " << map.right.at(3) << "\n";
    return 0;
}
