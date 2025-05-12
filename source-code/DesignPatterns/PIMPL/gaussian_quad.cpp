#include <vector>

#include "quad.h"

class Quad::QuadImpl {
    private:
        std::vector<double> w_;
        std::vector<double> x_;
    public:
        QuadImpl() {
            w_.push_back(0.2955242247147529);
            w_.push_back(0.2955242247147529);
            w_.push_back(0.2692667193099963);
            w_.push_back(0.2692667193099963);
            w_.push_back(0.2190863625159820);
            w_.push_back(0.2190863625159820);
            w_.push_back(0.1494513491505806);
            w_.push_back(0.1494513491505806);
            w_.push_back(0.0666713443086881);
            w_.push_back(0.0666713443086881);

            x_.push_back(-0.1488743389816312);
            x_.push_back(0.1488743389816312);
            x_.push_back(-0.4333953941292472);
            x_.push_back(0.4333953941292472);
            x_.push_back(-0.6794095682990244);
            x_.push_back(0.6794095682990244);
            x_.push_back(-0.8650633666889845);
            x_.push_back(0.8650633666889845);
            x_.push_back(-0.9739065285171717);
            x_.push_back(0.9739065285171717);
        }
        double integrate(Integrand f, const double a, const double b) const {
            double h {0.5*(b - a)};
            double k {0.5*(a + b)};
            double sum {0.0};
            for (unsigned i = 0; i < w_.size(); ++i) {
                sum += w_[i]*f(h*x_[i] + k);
            }
            return h*sum;
        }
};

Quad::Quad() : impl {std::make_unique<QuadImpl>()} {}
double Quad::integrate(Integrand f, const double a, const double b) const {
    return impl->integrate(f, a, b);
}
Quad::~Quad() = default;
