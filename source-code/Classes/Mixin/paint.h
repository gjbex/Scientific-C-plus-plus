#ifndef PAINT_HDR
#define PAINT_HDR

#include "color.h"

class Paint: public Color {
    private:
        float price_per_liter_;
    public:
        Paint(float price_per_liter, RGB rgb) : price_per_liter_ {price_per_liter} {
            set_color(rgb);
        }
        float price_per_liter() const { return price_per_liter_; }
};

#endif
