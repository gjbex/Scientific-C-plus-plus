#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include "circle.h"
#include "shape.h"
#include "square.h"
#include "triangle.h"

using Data = std::vector<Shape*>;

double total_area(const Data& data) {
    double total = 0;
    for (const auto& shape : data) {
        total += shape->area();
    }
    return total;
}

Data create_shapes(std::size_t nr_shapes) {
    Data data;
    std::mt19937 gen(0);
    std::uniform_real_distribution<double> size_dist(1, 10);
    std::uniform_int_distribution<int> shape_dist(0, 2);
    for (std::size_t i = 0; i < nr_shapes; ++i) {
        switch (shape_dist(gen)) {
            case 0:
                data.push_back(new Circle(size_dist(gen)));
                break;
            case 1:
                data.push_back(new Square(size_dist(gen)));
                break;
            case 2:
                data.push_back(new Triangle(size_dist(gen), size_dist(gen)));
                break;
        }
    }
    return data;
}

int main(int argc, char* argv[]) {
    std::size_t nr_shapes = 10;
    if (argc > 1) {
        nr_shapes = std::stoul(argv[1]);
    }
    auto start = std::chrono::high_resolution_clock::now();
    /*
    Data data = create_shapes(nr_shapes);
    */
    Data data {create_shapes(nr_shapes)};   
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time to create: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Total area: " << total_area(data) << std::endl;
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Time to calculate: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
}
