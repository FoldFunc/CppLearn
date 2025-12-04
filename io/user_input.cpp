#include <charconv>
#include <expected>
#include <iostream>
#include <print>
#include <string>
#include <system_error>
std::string intstr(int tostr) {
  return std::to_string(tostr);
}
std::expected<int, std::string> strint(std::string intiger) {
  int value = 0;
  auto [ptr, ec] = std::from_chars(intiger.data(), intiger.data()+ intiger.size(), value);
  if (ec == std::errc()) return value;
  return std::unexpected("Invalid integer");
}
int age() {
  int ok = 1;
  while (ok == 1) {
    std::string user_age;
    std::print("What is your age?: ");
    std::getline(std::cin, user_age);
    auto int_age = strint(user_age);
    if (int_age) return *int_age;
  }
}
int main() {
  std::string name;
  std::print("What is your name?: ");
  std::getline(std::cin, name);
  int agee = age();
  std::println("\nYour name is: {}", name);
  std::println("Your age is: {}", agee);
  return 0;
}
