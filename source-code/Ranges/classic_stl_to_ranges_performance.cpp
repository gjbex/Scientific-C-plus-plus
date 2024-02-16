#include <algorithm>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ranges>
#include <vector>

using DataType = std::int64_t;
using Data = std::vector<DataType>;

int main() {
    const size_t data_size {300'000'000};
    // define filter function and number of items to skip
    auto is_even = [] (DataType i) { return i % 2 == 0; };
    const int skip {3'000};
    // create initial data set
    Data data(data_size);
    std::iota(data.begin(), data.end(), 1);
    std::cout << "ranges:\n";
    // filter only even numbers
    auto start_time = std::chrono::high_resolution_clock::now();
    Data temp1;
    std::copy_if(data.begin(), data.end(), std::back_inserter(temp1), is_even);
    // skip the first three values
    Data temp2(temp1.begin() + skip, temp1.end());
    auto sum {std::accumulate(temp2.cbegin(), temp2.cend(), 0)};
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "elapsed time: " << elapsed_time << " ms\n";
    std::cout << "sum: " << sum << "\n";
    // now with views
    std::cout << "views:\n";
    start_time = std::chrono::high_resolution_clock::now();
    sum = std::ranges::fold_left(
        data
        | std::ranges::views::filter(is_even)
        | std::ranges::views::drop(skip),
        0, std::plus<DataType>());
    end_time = std::chrono::high_resolution_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "elapsed time: " << elapsed_time << " ms\n";
    std::cout << "sum: " << sum << "\n";
    return 0;
}
