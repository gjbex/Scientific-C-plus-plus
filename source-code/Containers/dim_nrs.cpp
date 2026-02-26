#include <iostream>
#include <unordered_set>


int main(void) {
    std::string col1, col2, col3;
    std::cin >> col1 >> col2 >> col3;
    int id, dim_nr;
    double temp;
    std::unordered_set<int> dim_nrs;
    while (std::cin >> id >> dim_nr >> temp)
        dim_nrs.insert(dim_nr);
    for (auto dim_nr: dim_nrs)
        std::cout << dim_nr << std::endl;
    return 0;
}
