#include <iostream>
#include <unordered_map>


int main(void) {
    std::string col1, col2, col3;
    std::cin >> col1 >> col2 >> col3;
    int id, dim_nr;
    double temp;
    std::unordered_map<int, int> dim_nr_counts;
    while (std::cin >> id >> dim_nr >> temp)
        dim_nr_counts[dim_nr]++;
    for (auto dim_nr: dim_nr_counts)
        std::cout << dim_nr.first << ": " << dim_nr.second << std::endl;
    return 0;
}

