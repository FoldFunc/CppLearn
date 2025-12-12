#include <charconv>
#include <print>
#include <string>
#include <iostream>
#include <system_error>
#include <type_traits>
#include <utility>
int encode(int data, int key) {
  return data ^ key;
}
int decode(int encoded_data, int key) {
  return encoded_data ^ key;
}
template <class T>
auto parse(std::string sv) -> std::pair<T, std::errc> {
  if constexpr (std::is_same_v<T, std::string>) {
    return { std::string(sv), std::errc{} };
  }
  else if constexpr (std::is_arithmetic_v<T>) {
    T value{};
    auto begin = sv.data();
    auto end = sv.data() + sv.size();
    auto [ptr, ec] = std::from_chars(begin, end, value);
    if (ec == std::errc{} && ptr != end) {
      ec = std::errc::invalid_argument;
    }
    return { value, ec };
  } else {
    static_assert(!sizeof(T), "parse<T>: no parser defined for this type.");
  }
}
int main() {
  bool run = true;
  int num;
  while (run) {
    std::println("Give me a number that you want to euncode: ");
    std::string line;
    std::getline(std::cin, line);
    auto [number, ec] = parse<int>(line);
    if (ec != std::errc{}) {
      std::println("Invalid input, please try again.");
    } else {
      num = number;
      run = false;
    }
  }
  run = true;
  int key; 
  while (run) {
    std::println("Give me a number that will be your decoding number: ");
    std::string line;
    std::getline(std::cin, line);
    auto [hasher, ec] = parse<int>(line);
    if (ec != std::errc{}) {
      std::println("Invalid input, please try again.");
    } else {
      run = false;
      key = hasher;
    }
  }
  std::println("Encoded number of yours is: {}", encode(num, key));
  return 0;
}
