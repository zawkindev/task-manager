#include "../include/transpiler.h"
#include "../include/task_manager.h"
#include <iostream>
#include <vector>

void fetchCategories(std::vector<Category> *categories, std::string filename) {
  std::string str;

  readFile(&str, filename);

  std::cout << str;
}
