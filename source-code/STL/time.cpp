#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <thread>

int main() {
    for (int iter = 0; iter < 10; ++iter) {
        auto time {std::chrono::system_clock::now()};
        auto duration = time.time_since_epoch();
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration).count() % 1'000'000;
        auto time_c {std::chrono::system_clock::to_time_t(time)};
        auto tm {std::localtime(&time_c)};
        std::cout << std::put_time(tm, "%Y-%m-%d %H:%M:%S")
                  << "." << microseconds << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    return 0;
}
