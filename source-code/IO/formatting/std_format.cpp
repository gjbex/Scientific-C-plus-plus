#include <cmath>
#include <format>
#include <iostream>
#include <numbers>
#include <string>

int main() {
  std::string s1 = std::format("The answer is {}.", 42);
  std::cout << s1 << std::endl;
  const double PI {std::numbers::pi};
  std::string s2 = std::format("PI is {:.3f}.", PI);
  std::cout << s2 << std::endl;
}
