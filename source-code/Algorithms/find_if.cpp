#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v {{1, 3, 7, 14}};
    for (auto target: {2, 4, 9, 18}) {
        auto it = std::find_if(v.cbegin(), v.cend(),
                          [target] (int x) { return x > target; });
        if (it != v.cend())
            std::cout << "found " << *it << " > " << target << std::endl;
        else
            std::cout << "no element > " << target << std::endl;
    }
    return 0;
}
