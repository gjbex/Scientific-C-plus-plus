#include <vector>
#include <fmt/core.h>
#include <fmt/ranges.h>

int main() {
    std::vector<double> data {3.1, 5.2, 7.3};
  fmt::print("data = {} has {} elements\n", data, data.size());
  return 0;
}
