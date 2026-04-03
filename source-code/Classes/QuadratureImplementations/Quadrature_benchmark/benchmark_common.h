#ifndef QUADRATURE_BENCHMARK_COMMON_H
#define QUADRATURE_BENCHMARK_COMMON_H

#include <chrono>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

struct BenchmarkConfig {
    unsigned simpson_panels {100};
    std::size_t repetitions {2000000};
};

inline double benchmark_integrand(double x) {
    return std::sin(x)*std::cos(0.5*x) + 0.01*x*x + 1.0;
}

inline BenchmarkConfig parse_benchmark_config(int argc, char* argv[]) {
    BenchmarkConfig config;
    if (argc > 1)
        config.repetitions = std::stoull(argv[1]);
    if (argc > 2)
        config.simpson_panels = static_cast<unsigned>(std::stoul(argv[2]));

    if (config.repetitions == 0)
        throw std::invalid_argument("repetitions must be positive");
    if (config.simpson_panels == 0 || config.simpson_panels % 2 != 0)
        throw std::invalid_argument("simpson_panels must be a positive even number");

    return config;
}

template<typename IntegrateOnce>
double run_workload(std::size_t repetitions, IntegrateOnce integrate_once) {
    double checksum {0.0};
    for (std::size_t rep = 0; rep < repetitions; ++rep) {
        const double shift = 0.000001*static_cast<double>(rep % 1000);
        checksum += integrate_once(-1.0 - shift, 1.0 + shift);
        checksum += integrate_once(-2.0 - shift, 2.0 + shift);
        checksum += integrate_once(-3.0 - shift, 3.0 + shift);
        checksum += integrate_once(-4.0 - shift, 4.0 + shift);
        checksum += integrate_once(-5.0 - shift, 5.0 + shift);
    }
    return checksum;
}

template<typename IntegrateOnce>
void execute_benchmark(const std::string& dispatch_name,
                       const BenchmarkConfig& config,
                       IntegrateOnce integrate_once) {
    const auto start = std::chrono::steady_clock::now();
    const double checksum = run_workload(config.repetitions, integrate_once);
    const auto stop = std::chrono::steady_clock::now();

    const std::chrono::duration<double> elapsed = stop - start;
    const double calls =
        5.0*static_cast<double>(config.repetitions);
    const double ns_per_integral = 1.0e9*elapsed.count()/calls;

    std::cout << "dispatch=" << dispatch_name
              << " repetitions=" << config.repetitions
              << " simpson_panels=" << config.simpson_panels
              << " elapsed_seconds=" << std::setprecision(9)
              << elapsed.count()
              << " ns_per_integral=" << std::setprecision(9)
              << ns_per_integral
              << " checksum=" << std::setprecision(17)
              << checksum
              << '\n';
}

#endif
