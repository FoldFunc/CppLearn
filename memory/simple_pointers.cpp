#include <print>
int main() {
  int x = 10;
  int *ptr = &x;
  for (int i = 0;i<10;i++) {
    // Some good old pointer arithmetics in c++ //
    ptr += i;
  }
  std::println("{}", static_cast<void *>(ptr));
  std::println("{}", *ptr);
  return 0;
}
