#ifndef SHAPE_HDR
#define SHAPE_HDR

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
                const T* shape_;
            public:
                explicit ShapeModel(const T* shape) : shape_(shape) {}
                double area() const override { return shape_->area(); }
                double perimeter() const override { return shape_->perimeter(); }
                T* get() const { return shape_; }
        };
        
        std::vector<ShapeConcept*> shapes_;
        
    public:
        template<typename T>
        void add(const T* shape) {
            shapes_.push_back(new ShapeModel<T>(shape));
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
