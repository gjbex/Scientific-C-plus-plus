#include <functional>
#include <ostream>

class StaticParticle {
    protected:
        double x_, y_;
        double mass_;
    public:
        StaticParticle(double x, double y, double mass) :
            x_ {x},
            y_ {y},
            mass_ {mass} {};
        StaticParticle(StaticParticle&) = default;
        StaticParticle(StaticParticle&&) = default;
        ~StaticParticle() = default;
        double x() const { return x_; }
        double y() const { return y_; }
        double mass() const {return mass_; }
        virtual double energy() const;
        double dist(const StaticParticle& other) const;
        friend std::ostream& operator<<(std::ostream& out,
                                        const StaticParticle& p);
};
