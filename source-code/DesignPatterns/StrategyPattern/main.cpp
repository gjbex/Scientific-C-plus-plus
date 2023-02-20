#include <iostream>
#include <memory>
#include <random>
#include <tuple>
#include "automaton_runner.h"
#include "cycle_finder.h"

Automaton init_automaton(const size_t nr_cells, const size_t seed) {
    Automaton automaton(nr_cells);
    std::mt19937_64 engine(seed);
    std::uniform_int_distribution<uint8_t> distr(0, 1);
    for (size_t cell_nr = 0; cell_nr < automaton.size(); ++cell_nr) {
        automaton[cell_nr] = distr(engine);
    }
    return automaton;
}

class PrintHandler: public GenerationHandler {
    public:
        bool handle(const Automaton& automaton) override {
            for (const auto& value: automaton) {
                if (value == 0) {
                    std::cout << ' ';
                } else {
                    std::cout << 'X';
                }
            }
            std::cout << '\n';
            return true;
        }
};

class DoNothingHandler: public GenerationHandler {
    public:
        bool handle([[maybe_unused]] const Automaton& automaton) override {
            return true;
        }
};

struct Options {
    size_t nr_cells;
    uint8_t rule_nr;
    size_t nr_generations;
    size_t seed;
    std::unique_ptr<GenerationHandler> handler;
};

Options get_options(int argc, char *argv[]) {
    Options options {10, 47, 20, 1234,
        std::make_unique<PrintHandler>()};
    int i {1};
    while (i < argc) {
        std::string opt {argv[i]};
        if (opt == "--nr_cells") {
            options.nr_cells = std::stoul(argv[i + 1]);
        } else if (opt == "--rule_nr") {
            options.rule_nr = static_cast<uint8_t>(std::stoi(argv[i + 1]));
        } else if (opt == "--nr_generations") {
            options.nr_generations = std::stoul(argv[i + 1]);
        } else if (opt == "--seed") {
            options.seed = std::stoul(argv[i + 1]);
        } else if (opt == "--handler") {
            std::string handler_str {argv[i + 1]};
            if (handler_str == "nothing") {
                options.handler = std::make_unique<DoNothingHandler>();
            } else if (handler_str == "visualize") {
                options.handler = std::make_unique<PrintHandler>();
            } else if (handler_str == "cycles") {
                options.handler = std::make_unique<CycleFinder>();
            } else {
                std::cerr << "# error: unknown handler type " << handler_str << "\n";
                std::exit(2);
            }
        } else {
            std::cerr << "# error: unexpected argument " << opt << "\n";
            std::exit(1);
        }
        i += 2;
    }
    return options;
}

int main(int argc, char *argv[]) {
    Options options {get_options(argc, argv)};
    Automaton automaton = init_automaton(options.nr_cells, options.seed);
    AutomatonRunner runner(options.rule_nr);
    runner.evolve(automaton, options.nr_generations, options.handler.get());
    if (CycleFinder* gen_handler = dynamic_cast<CycleFinder*>(options.handler.get());
            gen_handler != nullptr) {
        std::cout << gen_handler->cycle_length() << "\n";
    }
    return 0;
}
