#include <iostream>

int main() {
  int a = 2;
  int *p = &a;

  std::cout << typeid(&a).name();

  return 0;
}
