#include <iostream>
#include <tuple>

#include "paint.h"
#include "pixel.h"

int main() {
    RGB rgb = std::make_tuple(255, 255, 255);
    {
        Pixel point {3, 5, rgb};
        auto [red, green, blue] = point.color();
        std::cout << "(" << point.x() << ", " << point.y() << "): "
            << "(" << static_cast<int>(red)
            << ":" << static_cast<int>(green)
            << ":" << static_cast<int>(blue) << ")\n";
    }
    {
        Paint paint {3.5, rgb};
        auto [red, green, blue] = paint.color();
        std::cout << "price = " << paint.price_per_liter()  << ": "
            << "(" << static_cast<int>(red)
            << ":" << static_cast<int>(green)
            << ":" << static_cast<int>(blue) << ")\n";
    }
    return 0;
}
