#ifndef PIXEL_HDR
#define PIXEL_HDR

#include "point.h"
#include "color.h"

class Pixel: public Point, public Color {
    public:
        Pixel(int x, int y, RGB& rgb) : Point {x, y} {
            set_color(rgb);
        }
};

#endif
