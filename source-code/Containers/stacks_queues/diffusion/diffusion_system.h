#include <functional>
#include <iostream>
#include <queue>
#include <random>


class Particle {
    private:
        double _time;
        int _id;
        double _mass;
        int _x, _y;
        std::function<double()> _time_distr;
        std::mt19937_64* _engine;
    public:
        Particle(int id, double mass, int x, int y, std::mt19937_64* engine) :
            _id {id}, _mass {mass}, _x {x}, _y {y}, _engine {engine}
        {
            _time_distr = std::bind(std::gamma_distribution<double>(1.0, _mass),
                               std::ref(*_engine));
            _time = _time_distr();
        };
        double mass() const { return _mass; };
        int x() const { return _x; };
        int y() const { return _y; };
        double time() const { return _time; };
        void update() {  };
        bool operator<(const Particle& other) const {
            return this->time() < other.time();
        };
        void update(int x, int y) {
            _time += _time_distr(); _x = x; _y = y;
        };
        friend std::ostream& operator<<(std::ostream& out, const Particle& p);
};


bool cmp(const Particle& p1, const Particle& p2);
using cmp_t = std::function<bool(const Particle&, const Particle&)>;
using Particle_queue =  std::priority_queue<Particle, std::vector<Particle>, cmp_t>;

class System {
    private:
        std::size_t _nr_patricles, _grid_size;
        Particle_queue* _queue;
        bool* _grid;
        std::mt19937_64* _engine;
        std::uniform_int_distribution<int> _pos_distr;
        std::poisson_distribution<int> _mass_distr;
        std::uniform_int_distribution<int> _move_distr;
        int* find_moves(const Particle& particle);
    public:
        System(std::size_t nr_particles, std::size_t grid_size);
        ~System();
        void print_grid() const;
        void print_queue() const;
        double update();
};
