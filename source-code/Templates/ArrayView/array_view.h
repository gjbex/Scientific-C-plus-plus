#ifndef ARRAY_VIEW_HDR
#define ARRAY_VIEW_HDR

#include <array>
#include <stdexcept>

template<typename T, std::size_t ...Dims>
struct ArrayView {
    protected:
        T* data_;
        const std::size_t size_ = static_cast<std::size_t>((Dims * ...));
        const std::array<std::size_t, sizeof...(Dims)> dims_{Dims...};
    public:
        explicit ArrayView(T* data) : data_(data) {
            static_assert(sizeof...(Dims) > 0,
                    "ArrayView must have at least one dimension");
        }
        ArrayView(const ArrayView&) = default;
        ArrayView& operator=(const ArrayView&) = default;
        ArrayView(ArrayView&&) noexcept = default;
        ArrayView& operator=(ArrayView&&) noexcept = default;
        ~ArrayView() = default;
        template<typename ...Indices>
        T& operator()(std::size_t idx, Indices... indices) {
            return const_cast<T&>(static_cast<const ArrayView*>(this)->operator()(idx, indices...));
        }
        template<typename ...Indices>
        const T& operator()(std::size_t idx, Indices... indices) const {
            static_assert(sizeof...(Dims) == 1 + sizeof...(Indices),
                    "Number of indices must match number of dimensions");
            const std::array<std::size_t, sizeof...(Dims)> idxs{idx, indices...};
            std::size_t index {0};
            std::size_t stride {size_};
            for (std::size_t i = 0; i < dims_.size(); ++i) {
                stride /= dims_[i];
                index += idxs[i]*stride;
            }
            return data_[index];
        }
        std::size_t size() const { return size_; }
        std::array<std::size_t, sizeof...(Dims)> shape() const { return dims_; }
        std::size_t shape(std::size_t dim) const {
            return dims_[dim];
        }
        std::size_t ndim() const {
            return dims_.size();
        }
        T* data() {
            return data_;
        }
        const T* data() const {
            return data_;
        }
};

#endif
