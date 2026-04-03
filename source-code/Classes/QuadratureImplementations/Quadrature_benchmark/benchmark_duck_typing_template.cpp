#include <exception>
#include <iostream>

#include "benchmark_common.h"
#include "simpson_quad.h"

namespace {

template<typename QuadType>
void benchmark_duck_typed_quad_template(const BenchmarkConfig& config,
                                        const QuadType& quad) {
    execute_benchmark("duck_typing_template_static", config,
                      [&quad](double a, double b) {
                          return quad.integrate(benchmark_integrand, a, b);
                      });
}

} // namespace

int main(int argc, char* argv[]) {
    try {
        const BenchmarkConfig config = parse_benchmark_config(argc, argv);
        const SimpsonQuad quad(config.simpson_panels);
        benchmark_duck_typed_quad_template(config, quad);
    } catch (const std::exception& error) {
        std::cerr << "### error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
