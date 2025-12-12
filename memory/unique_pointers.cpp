// This I hope ain't deprecated
#include <memory>
#include <print>
int main() {
  std::unique_ptr<int> ptr(new int(10));
  std::println("{}", static_cast<void *>(ptr.get()));
  return 0;
}
