#include <iostream>
#include <print>
struct Point {
  int x;
  int y;
};
Point point_constructor(int x, int y) {
  Point p;
  p.x = x;
  p.y = y;
  return p;
}
int main() {
  int x = 10;
  int y = 20;
  Point p = point_constructor(x, y);
  std::println("p.x: {}", p.x);
  std::println("p.y: {}", p.y);
  return 0;
}
