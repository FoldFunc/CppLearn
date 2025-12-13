#include <print>
import calc;

int main() {
  int a = 10;
  int b = 20;
  std::println("Addition: {}", add(a, b));
  std::println("Substraction: {}", sub(a, b));
  std::println("Multiplication: {}", mul(a, b));
  std::println("Division: {}", division(a, b));
}
