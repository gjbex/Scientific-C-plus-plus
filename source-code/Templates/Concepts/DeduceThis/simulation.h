#ifndef SIMULATION_HDR
#define SIMULATION_HDR

#include <concepts>
#include <cstdint>
#include <iostream>

template <typename StopFunction, typename SimulationType>
concept StopCondition =
    requires(const StopFunction& stop_function, SimulationType& simulation,
             std::size_t step_nr) {
        { stop_function(simulation, step_nr) } -> std::convertible_to<bool>;
    };

struct Simulation {
    protected:
        bool is_verbose_ {false};
        std::size_t current_step_ {0};
    public:
        bool is_verbose() const { return is_verbose_; }
        void set_verbosity(const bool is_verbose) { is_verbose_ = is_verbose; }
        void step(this auto& self) {
            if (self.is_verbose_) {
                std::cout << "starting step " << self.current_step_ << '\n';
            }
            self.step_implementation();
            if (self.is_verbose_) {
                std::cout << "step " << self.current_step_ << "done\n";
            }
            self.current_step_++;
        }
        void run(this auto& self, const std::size_t max_nr_steps) {
            for (size_t step_nr = 0; step_nr < max_nr_steps; ++step_nr) {
                self.step();
            }
        }
        template <typename StopFunction>
        void run(this auto& self, const StopFunction& stop_function)
        requires StopCondition<StopFunction, decltype(self)>
        {
            std::size_t step_nr {0};
            while (!stop_function(self, step_nr)) {
                self.step();
                ++step_nr;
            }
        }
        std::size_t current_step() const { return current_step_; }
};

#endif
