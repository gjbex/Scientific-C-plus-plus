#include <exception>
#include <iostream>

#include "benchmark_common.h"
#include "simpson_quad.h"

int main(int argc, char* argv[]) {
    try {
        const BenchmarkConfig config = parse_benchmark_config(argc, argv);
        const SimpsonQuad quad(config.simpson_panels);
        const Quad* const quad_ptr = &quad;
        const Integrand integrand = benchmark_integrand;
        execute_benchmark("runtime_virtual", config,
                          [quad_ptr, &integrand](double a, double b) {
                              return quad_ptr->integrate(integrand, a, b);
                          });
    } catch (const std::exception& error) {
        std::cerr << "### error: " << error.what() << '\n';
        return 1;
    }
    return 0;
}
