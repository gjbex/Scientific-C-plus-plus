#include <exception>
#include <iostream>

#include "benchmark_common.h"
#include "simpson_quad.h"

namespace {

template<typename QuadType>
void benchmark_duck_typed_quad(const BenchmarkConfig& config,
                               const QuadType& quad) {
    const Integrand integrand = benchmark_integrand;
    execute_benchmark("duck_typing_static", config,
                      [&quad, &integrand](double a, double b) {
                          return quad.integrate(integrand, a, b);
                      });
}

} // namespace

int main(int argc, char* argv[]) {
    try {
        const BenchmarkConfig config = parse_benchmark_config(argc, argv);
        const SimpsonQuad quad(config.simpson_panels);
        benchmark_duck_typed_quad(config, quad);
    } catch (const std::exception& error) {
        std::cerr << "### error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
