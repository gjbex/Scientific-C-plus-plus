#include <algorithm>
#include <cmath>
#include <iostream>
#include <fstream>
#include <numbers>
#include <sstream>
#include <valarray>
#include <vector>

using std::cos;


using wave_t = std::pair<double, double>;

std::vector<wave_t> read_wave_properties();

int main() {
    const double pi {std::numbers::pi};
    const std::size_t nr_points {1000};
    const double delta_t {10.0*pi/nr_points};
    auto waves = read_wave_properties();
    std::valarray<double> time(nr_points);
    std::generate(std::begin(time), std::end(time),
             [delta_t] () {
                 static double t {0.0};
                 auto curr_time = t;
                 t += delta_t;
                 return curr_time;
            }); 
    std::valarray<double> signal(0.0, nr_points);
    for (auto wave: waves) {
        auto freq = wave.first;
        auto phase = wave.second;
        signal += cos(2.0*pi*freq*time + phase);
    }
    for (std::size_t i = 0; i < time.size(); i++)
        std::cout << time[i] << "\t" << signal[i] << std::endl;
    return 0;
}

std::vector<wave_t> read_wave_properties() {
    std::vector<wave_t> waves;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream stream(line);
        double freq, phase;
        stream >> freq >> phase;
        waves.push_back(wave_t(freq, phase));
    }
    return waves;
}
