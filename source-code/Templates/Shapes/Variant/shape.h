#ifndef SHAPE_HDR
#define SHAPE_HDR

template<typename T>
concept is_shape = requires(T a, T b) {
    { a.area() };
    { a.perimeter() };
};

#endif
