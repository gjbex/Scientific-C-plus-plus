#include <set>
#include <random>

using Seed = std::mt19937::result_type;
using Stuff = std::multiset<int>;

Stuff fill_stuff_random(int nr_items, Seed seed=1234);
