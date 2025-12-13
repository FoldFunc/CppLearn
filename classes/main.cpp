#include <print>
class Calculator {
public:
  Calculator(int x, int y) noexcept
    : x_{x}, y_{y} {}
  [[nodiscard]] int x() const noexcept { return x_; }
  [[nodiscard]] int y() const noexcept { return y_; }

  constexpr int add() {
    return x_ + y_;
  }
  constexpr int mul() {
    return x_ * y_;
  }
  constexpr int sub() {
    return x_ - y_;
  }
  constexpr int divi() {
    if (y_ != 0) return x_ / y_;
    return -1;
  }

private:
  int x_;
  int y_;
};
int main() {
  Calculator calc = Calculator(10, 20);
  std::println("{}", calc.add());
  std::println("{}", calc.sub());
  std::println("{}", calc.mul());
  std::println("{}", calc.divi());
  return 0;
}
