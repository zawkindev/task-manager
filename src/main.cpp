#include "../include/transpiler.h"
#include <vector>

int main() {
  std::vector<Category> c;

  fetchCategories(&c, "src/data.todo");

  return 0;
}
