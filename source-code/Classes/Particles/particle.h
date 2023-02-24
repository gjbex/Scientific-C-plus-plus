#include <ostream>
#include "static_particle.h"

class Particle : public StaticParticle {
    private:
        double v_x_, v_y_;
    public:
        Particle(double x, double y, double v_x, double v_y, double mass)
            : StaticParticle(x, y, mass), v_x_ {v_x}, v_y_ {v_y} {
            };
        double v_x() const { return v_x_; };
        double v_y() const { return v_y_; };
        double energy() const override;
        void move(double t);
        friend std::ostream& operator<<(std::ostream& out,
                                        const Particle& p);
};
