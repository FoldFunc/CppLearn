export module calc;

export inline int add(int a, int b) {
  return a + b;
}
export inline int sub(int a, int b) {
  return a - b;
}
export inline int mul(int a, int b) {
  return a * b;
}
export inline float division(int a, int b) {
  if (b != 0) return a / b;
  else {
    return -1;
  }
}
