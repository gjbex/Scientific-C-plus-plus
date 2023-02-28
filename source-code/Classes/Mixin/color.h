#ifndef COLOR_HDR
#define COLOR_HDR

#include <cstdint>
#include <tuple>

using RGB = std::tuple<uint8_t, uint8_t, uint8_t>;

class Color {
    protected:
        uint8_t red_, green_, blue_;
    public:
        RGB color() const { return std::make_tuple(red_, green_, blue_); }
        void set_color(uint8_t red, uint8_t green, uint8_t blue) {
            red_ = red;
            green_ = green;
            blue_ = blue;
        }
        void set_color(RGB& rgb) {
            red_ = std::get<0>(rgb);
            green_ = std::get<1>(rgb);
            blue_ = std::get<2>(rgb);
        }
};

#endif
