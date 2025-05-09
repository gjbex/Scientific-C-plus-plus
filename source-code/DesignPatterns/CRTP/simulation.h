#ifndef SIMULATION_HDR
#define SIMULATION_HDR

#include <cstdint>
#include <functional>
#include <iostream>

template <class Derived>
using StopFunction = std::function<bool(const Derived&, const std::size_t)>;

template<class Derived>
struct Simulation {
    protected:
        bool is_verbose_ {false};
        std::size_t current_step_ {0};
    public:
        bool is_verbose() const { return is_verbose_; }
        void set_verbosity(const bool is_verbose) { is_verbose_ = is_verbose; }
        void step() {
            if (is_verbose_) {
                std::cout << "starting step " << current_step_ << '\n';
            }
            static_cast<Derived*>(this)->step_implementation();
            if (is_verbose_) {
                std::cout << "step " << current_step_ << "done\n";
            }
            current_step_++;
        }
        void run(const std::size_t max_nr_steps) {
            for (size_t step_nr = 0; step_nr < max_nr_steps; ++step_nr) {
                step();
            }
        }
        void run(const StopFunction<Derived>& stop_function) {
            std::size_t step_nr {0};
            while (!stop_function(*static_cast<Derived*>(this), step_nr)) {
                step();
                step_nr++;
            }
        }
        std::size_t current_step() const { return current_step_; }
};

#endif
