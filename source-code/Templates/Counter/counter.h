#ifndef COUNTER_HDR
#define COUNTER_HDR

#include <algorithm>
#include <iterator>
#include <utility>
#include <valarray>

template<typename ITEM_T, typename COUNT_T>
struct Counter {
    private:
        std::valarray<COUNT_T> values_;

    public:
        ITEM_T const lower;
        ITEM_T const upper;

        struct iterator {
            private:
                ITEM_T value;
                COUNT_T* count;

            public:
                using iterator_category = std::input_iterator_tag;
                using value_type = std::pair<ITEM_T, COUNT_T>;
                using difference_type = std::ptrdiff_t;
                using pointer = std::pair<ITEM_T, COUNT_T>*;
                using reference = std::pair<ITEM_T, COUNT_T>&;

                iterator(ITEM_T lower, COUNT_T* count) : value {lower}, count {count} {}
                iterator& operator++() { ++value; ++count; return *this; }
                iterator operator++(int) { iterator tmp = *this; ++value; ++count; return tmp; }
                bool operator==(iterator const& rhs) const { return value == rhs.value; }
                bool operator!=(iterator const& rhs) const { return value != rhs.value; }
                auto const operator*() const { return std::make_pair(value, *count); }
        };

        Counter(ITEM_T const lower, ITEM_T const upper) : lower {lower}, upper {upper},
           values_(COUNT_T(), upper - lower + 1) {}
        void incr(ITEM_T const value) { values_[value - lower]++; }
        void incr_at(ITEM_T const value) { values_.at(value - lower)++; }
        COUNT_T const& operator[](ITEM_T const value) const { return values_[value - lower]; }
        COUNT_T const& at(ITEM_T const value) const { return values_.at(value - lower); }
        iterator begin() { return iterator(lower, &values_[0]); }
        iterator end() { return iterator(upper + 1, &values_[upper - lower + 1]); }
        iterator const begin() const { return iterator(lower, &values_[0]); }
        iterator const end() const { return iterator(upper + 1, &values_[upper - lower + 1]); }
        iterator const cbegin() const { return iterator(lower, &values_[0]); }
        iterator const cend() const { return iterator(upper + 1, &values_[upper - lower + 1]); }

};

#endif
