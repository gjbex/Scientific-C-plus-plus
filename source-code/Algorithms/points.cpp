#include <algorithm>
#include <compare>
#include <iostream>
#include <vector>

struct Point {
    double x, y;
    int id;
    auto operator<=>(const Point&) const = default;    
    friend std::ostream& operator <<(std::ostream& out, const Point& p);
};

std::ostream& operator <<(std::ostream& out, const Point& p) {
    return out << p.id << ": (" << p.x << ", " << p.y << ")";
}

int main() {
    std::vector<Point> points;
    points.emplace_back(4.1, 5.2, 1);
    points.emplace_back(2.1, 7.2, 2);
    points.emplace_back(1.2, 9.2, 3);
    points.emplace_back(2.1, 3.2, 4);
    points.emplace_back(2.1, 3.2, 5);
    std::sort(points.begin(), points.end());
    for (const auto& point: points) {
        std::cout << point << "\n";
    }
    return 0;
}
