#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <vector>

using Data = std::vector<int>;

void show_vector(const Data& data) {
    std::copy(data.begin(), data.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}

int main() {
    // define filter function and number of items to skip
    auto is_even = [] (int i) { return i % 2 == 0; };
    const int skip {3};
    // create initial data set
    Data data(20);
    std::iota(data.begin(), data.end(), 1);
    show_vector(data);
    // filter only even numbers
    Data temp;
    std::copy_if(data.begin(), data.end(), std::back_inserter(temp),
                 is_even);
    show_vector(temp);
    // skip the first three values
    Data temp2(temp.begin() + skip, temp.end());
    for (auto it = temp2.rbegin(); it != temp2.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    // now with ranges
    std::ranges::reverse_view rv {
        std::ranges::drop_view {
            std::ranges::filter_view {data, is_even}, skip 
        }
    };
    std::cout << "ranges:\n";
    for (const auto& value: rv) {
        std::cout << value << " ";
    }
    std::cout << "\n";
    // now with views
    std::cout << "now with views:\n";
    for (const auto& value: data
            | std::views::filter(is_even)
            | std::views::drop(skip)
            | std::views::reverse) {
        std::cout << value << " ";
    }
    std::cout << "\n";
    return 0;
}
