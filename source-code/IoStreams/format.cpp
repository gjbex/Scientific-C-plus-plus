#include <format>
#include <iostream>
#include <string>

int main() {
  std::string s = std::format("The answer is {}.", 42);
  std::cout << s << std::endl;
}
