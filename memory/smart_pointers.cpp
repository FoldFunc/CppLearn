#include <memory>
#include <print>
int main() {
  // auto_ptr is depricated beter to use unique_pointer in moderner c++ //
  std::auto_ptr<int> ptr1(new int(10));
  std::println("{}", *ptr1);
  std::auto_ptr<int> ptr2 = ptr1;
  std::println("{}", *ptr2);
  // std::println("Sneaky: {}", *ptr1); Segfault
  std::println("Hello world");
  return 0;
}
