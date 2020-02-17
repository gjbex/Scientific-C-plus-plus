#include "knapsack.h"

Stuff fill_stuff_random(int nr_items, Seed seed) {
    Stuff stuff;
    auto engine = std::mt19937(seed);
    auto distr = std::uniform_int_distribution<int>(1, nr_items);
    auto nr_distinct_items = distr(engine);
    distr = std::uniform_int_distribution<int>(1, nr_distinct_items);
    for (int item_nr = 0; item_nr < nr_items; ++item_nr) {
        auto item = distr(engine);
        stuff.insert(item);
    }
    return stuff;
}
