#include <chrono>
#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <random>
#include <ranges>
#include <tuple>
#include <valarray>

using std::sqrt;

using Vector = std::valarray<double>;
using my_time_t = std::chrono::nanoseconds;

Vector init_vector(std::size_t n, std::mt19937_64& engine);
void print_vector(const Vector& v);
double cos_similarity(const Vector& v1, const Vector& v2);
double cos_similarity_fast(const Vector& v1, const Vector& v2);

std::tuple<double, double> time(std::function<double(const Vector&, const Vector&)> f, const std::size_t n, const std::size_t nr_iters) {
    std::mt19937_64 engine;
    double total_time {0.0};
    double avg {0.0};
    for (std::size_t iter_nr = 0; iter_nr < nr_iters; iter_nr++) {
        Vector v1 {init_vector(n, engine)};
        Vector v2 {init_vector(n, engine)};
        auto start_time = std::chrono::steady_clock::now();
        avg += f(v1, v2);
        auto end_time = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<my_time_t>(end_time - start_time); 
        total_time += duration.count();
    }
    return std::make_tuple(total_time, avg/nr_iters);
}

int main() {
    const std::size_t nr_iters {100};
    const std::size_t n {100000};
    auto [time_naive, avg] = time(cos_similarity, n, nr_iters);
    auto [time_fast, avg_fast] = time(cos_similarity_fast, n, nr_iters);
    std::cout << "average cosine similarity: " << avg << std::endl;
    std::cout << "average cosine similarity fast: " << avg_fast << std::endl;
    std::cout << "cosine_similarity " << time_naive/1.0e6 << " ms" << std::endl;
    std::cout << "cosine_similarity_fast " << time_fast/1.0e6 << " ms" << std::endl;
    return 0;
}

Vector init_vector(std::size_t n, std::mt19937_64& engine) {
    auto distr = std::uniform_real_distribution<double>(-1.0, 1.0);
    Vector v(n);
    for (std::size_t i = 0; i < n; i++)
        v[i] = distr(engine);
    return v;
}

void print_vector(const Vector& v) {
    for (auto x: v)
        std::cout << x << " ";
    std::cout << std::endl;
}

double cos_similarity(const Vector& v1, const Vector& v2) {
    const double init {0.0};
    double r {std::inner_product(std::cbegin(v1), std::cend(v1), std::cbegin(v2), init)};
    double v1_norm {sqrt(std::inner_product(std::cbegin(v1), std::cend(v1),
                                       std::cbegin(v1), init))};
    double v2_norm {sqrt(std::inner_product(std::cbegin(v2), std::cend(v2),
                                       std::cbegin(v2), init))};
    return r/(v1_norm*v2_norm);
}

double cos_similarity_fast(const Vector& v1, const Vector& v2) {
    double r {0.0};
    double n1 {0.0};
    double n2 {0.0};
    for (std::size_t i = 0; i < v1.size(); i++) {
        r += v1[i]*v2[i];
        n1 += v1[i]*v1[i];
        n2 += v2[i]*v2[i];
    }
    return r/sqrt(n1*n2);
}
