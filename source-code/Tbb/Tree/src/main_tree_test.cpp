#include <chrono>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <random>

#include <oneapi/tbb/global_control.h>

#include "tree.h"
#include "sum_task.h"
#include "tree_init.h"

using my_time_t = std::chrono::nanoseconds;

int main(int argc, char* argv[]) {
    double child_prob {0.3};
    Seed_t seed {1234};
    std::size_t max_depth {20};
    std::unique_ptr<oneapi::tbb::global_control> global_control;
    if (argc > 1)
        child_prob = std::stod(argv[1]);
    if (argc > 2)
        max_depth = std::stoul(argv[2]);
    if (argc > 3)
        seed = std::stoul(argv[3]);
    if (const char* tbb_num_threads = std::getenv("TBB_NUM_THREADS")) {
        int nr_threads = std::stoi(tbb_num_threads);
        std::cout << "nr. threads = " << nr_threads << std::endl;
        global_control = std::make_unique<oneapi::tbb::global_control>(
            oneapi::tbb::global_control::max_allowed_parallelism,
            nr_threads
        );
    }
    TreeInit tree_init(child_prob, max_depth, seed);
    std::unique_ptr<Node_t> tree = tree_init.gen_random_tree();
    // print_tree<double>(std::cout, tree.get());
    // std::cout << std::endl;
    std::cout << "nr. nodes = " << 1 + tree->nr_descendants()
              << std::endl;
    double sum {0.0};
    auto start_time = std::chrono::steady_clock::now();
    sum = sum_values_parallel(tree.get());
    auto end_time = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<my_time_t>(end_time - start_time);
    std::cerr << "time: " << duration.count()*1.0e-9 << " s" << std::endl;
    std::cout << "sum = " << sum << std::endl;
    return 0;
}
