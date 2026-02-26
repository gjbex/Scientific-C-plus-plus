#include <chrono>
#include <iostream>
#include <cmath>
#include <numeric>
#include <random>
#include <valarray>


using Vector = std::valarray<double>;
using my_time_t = std::chrono::nanoseconds;

Vector init_vector(std::size_t n, std::mt19937_64& engine);
void print_vector(const Vector& v);
double cos_similarity(const Vector& v1, const Vector& v2);
double cos_similarity_fast(const Vector& v1, const Vector& v2);

int main() {
    const std::size_t nr_iters {100};
    const std::size_t n {100000};
    std::mt19937_64 engine;
    double dummy {0.0};
    my_time_t::rep time {0};
    my_time_t::rep time_fast {0};
    for (std::size_t iter_nr = 0; iter_nr < nr_iters; iter_nr++) {
        Vector v1 {init_vector(n, engine)};
        Vector v2 {init_vector(n, engine)};
        auto start_time = std::chrono::steady_clock::now();
        dummy += cos_similarity(v1, v2);
        auto end_time = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<my_time_t>(end_time - start_time); 
        time += duration.count();
        start_time = std::chrono::steady_clock::now();
        dummy += cos_similarity_fast(v1, v2);
        end_time = std::chrono::steady_clock::now();
        duration = std::chrono::duration_cast<my_time_t>(end_time - start_time); 
        time_fast = duration.count();
    }
    std::cout << "cosine_similarity " << time << " ns" << std::endl;
    std::cout << "cosine_similarity_fast " << time_fast << " ns" << std::endl;
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
    double v1_norm {std::sqrt(std::inner_product(std::cbegin(v1), std::cend(v1),
                                       std::cbegin(v1), init))};
    double v2_norm {std::sqrt(std::inner_product(std::cbegin(v2), std::cend(v2),
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
    return r/std::sqrt(n1*n2);
}
