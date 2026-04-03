#include <exception>
#include <iostream>

#include "benchmark_common.h"
#include "gaussian_quad.h"
#include "simpson_quad.h"

namespace {

void benchmark_simpson(const BenchmarkConfig& config) {
    const SimpsonQuad quad(config.simpson_panels);
    const Quad* const quad_ptr = &quad;
    const Integrand integrand = benchmark_integrand;
    execute_benchmark("runtime_virtual", config,
                      [quad_ptr, &integrand](double a, double b) {
                          return quad_ptr->integrate(integrand, a, b);
                      });
}

void benchmark_gaussian(const BenchmarkConfig& config) {
    const GaussianQuad quad;
    const Quad* const quad_ptr = &quad;
    const Integrand integrand = benchmark_integrand;
    execute_benchmark("runtime_virtual", config,
                      [quad_ptr, &integrand](double a, double b) {
                          return quad_ptr->integrate(integrand, a, b);
                      });
}

} // namespace

int main(int argc, char* argv[]) {
    try {
        const BenchmarkConfig config = parse_benchmark_config(argc, argv);
        if (config.method == "simpson")
            benchmark_simpson(config);
        else
            benchmark_gaussian(config);
    } catch (const std::exception& error) {
        std::cerr << "### error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
