#include <exception>
#include <iostream>

#include "benchmark_common.h"
#include "simpson_quad.h"

namespace {

template<typename QuadType>
void benchmark_static_dispatch(const std::string& dispatch_name,
                               const BenchmarkConfig& config,
                               const Quad<QuadType>& quad) {
    const Integrand integrand = benchmark_integrand;
    execute_benchmark(dispatch_name, config,
                      [&quad, &integrand](double a, double b) {
                          return quad.integrate(integrand, a, b);
                      });
}

} // namespace

int main(int argc, char* argv[]) {
    try {
        const BenchmarkConfig config = parse_benchmark_config(argc, argv);
        const SimpsonQuad quad(config.simpson_panels);
        benchmark_static_dispatch("crtp_static", config, quad);
    } catch (const std::exception& error) {
        std::cerr << "### error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
