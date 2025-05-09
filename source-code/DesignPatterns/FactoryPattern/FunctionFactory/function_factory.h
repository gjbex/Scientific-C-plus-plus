#ifndef FUNCTION_FACTORY_HDR
#define FUNCTION_FACTORY_HDR

#include <algorithm>
#include <functional>
#include <random>
#include <valarray>

template<typename T>
struct FunctionFactory {
    using Function = std::function<T(T)>;
    private:
        int degree_ {2};
        T min_coeff_ {-1.0};
        T max_coeff_ {1.0};
        std::mt19937_64 engine_;
        std::uniform_real_distribution<T> distr_;
    public:
        FunctionFactory(int degree, std::size_t seed) : degree_ {degree}, engine_(seed), distr_(min_coeff_, max_coeff_) {}
        Function create() {
            std::valarray<T> coefficients(degree_ + 1);
            std::generate(std::begin(coefficients), std::end(coefficients), [&] () {
                return distr_(engine_);
            });
            return [coefficients] (T x) -> T {
                int degree {static_cast<int>(coefficients.size()) - 1};
                T value {coefficients[degree]};
                for (int i = degree - 1; i >= 0; --i) {
                    value = coefficients[i] + value*x;
                }
                return value;
            };
        }
};

#endif
