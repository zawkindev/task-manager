#include "../include/transpiler.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<Category> c;

  fetchCategoryNames(&c, "src/data.todo");

  for (int i = 0; i < c.size(); i++) {
    std::cout << c[i].getName() << '\n';
  }

  return 0;
}
