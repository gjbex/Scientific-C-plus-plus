#include <iostream>
#include <numeric>
#include <set>

class Knapsack {
    private:
        int limit_;
        std::multiset<int> contents_;

    public:
        Knapsack(int limit) : limit_ {limit} {}
        bool add(const int value) {
            if (weight() + value <= limit()) {
                contents_.insert(value);
                return true;
            } else {
                return false;
            }
        }
        void remove(const int value) { contents_.erase(value); }
        int limit() const { return limit_; }
        int weight() const {
            return std::accumulate(contents_.begin(), contents_.end(), 0);
        }
        size_t nr_items() const { return contents_.size(); }
        friend std::ostream& operator<<(std::ostream& out,
                                        const Knapsack& knapsack);
};
