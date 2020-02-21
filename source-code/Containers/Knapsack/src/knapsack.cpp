#include "knapsack.h"


std::ostream& operator<<(std::ostream& out, const Knapsack& knapsack) {
    out << "contents:";
    for (const auto& value: knapsack.contents_)
        out << " " << value;
    return out;
}
