#include <chrono>
#include <cstdlib>
#include <iostream>

#include <oneapi/tbb/task_group.h>

class FibTask {
    private:
        static long task_threshold_;

        static void fib_serial(long n, long* result) {
            if (n < 2) {
                *result = 1;
            } else {
                long result_n_1 {0};
                long result_n_2 {0};
                fib_serial(n - 1, &result_n_1);
                fib_serial(n - 2, &result_n_2);
                *result = result_n_1 + result_n_2;
            }
        }

    public:
        static void run(long n, long* result) {
            if (n < task_threshold_) {
                fib_serial(n, result);
            } else {
                long result_n_1 {0};
                long result_n_2 {0};
                oneapi::tbb::task_group task_group;
                task_group.run([&] { run(n - 1, &result_n_1); });
                task_group.run([&] { run(n - 2, &result_n_2); });
                task_group.wait();
                *result = result_n_1 + result_n_2;
            }
        }

        static long task_threshold() { return task_threshold_; }

        static void set_task_threshold(long task_threshold) {
            task_threshold_ = task_threshold;
        }
};

long FibTask::task_threshold_ {10};

using my_time_t = std::chrono::nanoseconds;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: expecting positive integer as argument" << std::endl;
        std::exit(1);
    }
    long n {std::stol(argv[1])};
    if (n < 0) {
        std::cerr << "Error: expecting positive integer as argument" << std::endl;
        std::exit(1);
    }
    if (argc > 2)
        FibTask::set_task_threshold(std::stol(argv[2]));
    std::cout << "task threshold: " << FibTask::task_threshold() << std::endl;
    long result {0};
    auto start_time = std::chrono::steady_clock::now();
    FibTask::run(n, &result);
    auto end_time = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<my_time_t>(end_time - start_time);
    std::cout << "fib(" << n << ") = " << result << std::endl;
    std::cout << "time: " << duration.count()*1.0e-9 << " s" << std::endl;
    return 0;
}
