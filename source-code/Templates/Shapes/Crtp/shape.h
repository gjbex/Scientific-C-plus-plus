#ifndef SHAPE_HDR
#define SHAPE_HDR

struct IShape {
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~IShape() = default;
};

template<typename Derived>
struct Shape: public IShape {
    public:
        double area() const override {
            return static_cast<const Derived*>(this)->area_impl();
        }
        virtual double perimeter() const override {
            return static_cast<const Derived*>(this)->perimeter_impl();
        }
};

#endif
