#ifndef SHAPE_HDR
#define SHAPE_HDR

#include <memory>
#include <vector>

struct AreaAggregator {
    private:
        struct ShapeConcept {
            public:
                virtual double area() const = 0;
                virtual double perimeter() const = 0;
                virtual ~ShapeConcept() = default;
        };

        template<typename T>
        struct ShapeModel: public ShapeConcept {
            private:
                T shape_;
            public:
                explicit ShapeModel(T shape) : shape_{std::move(shape)} {}
                double area() const override { return shape_.area(); }
                double perimeter() const override { return shape_.perimeter(); }
        };
        
        std::vector<std::unique_ptr<ShapeConcept>> shapes_;
        
    public:
        template<typename T>
        void add(T shape) {
            shapes_.push_back(std::make_unique<ShapeModel<T>>(std::move(shape)));
        }
        double total_area() const {
            double total = 0;
            for (const auto& shape : shapes_) {
                total += shape->area();
            }
            return total;
        }

};

#endif
