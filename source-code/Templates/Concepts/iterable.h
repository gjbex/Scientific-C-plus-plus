#ifndef ITERABLE_HDR
#define ITERABLE_HDR

#include <iterator>

template <typename T>
concept Iterable = requires(T t) {
    { std::begin(t) } -> std::input_iterator;
    { std::end(t) } -> std::input_iterator;
};

#endif
