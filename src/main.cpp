#include "../include/task_manager.h"
#include "../include/transpiler.h"
#include <vector>

int main() {
  std::vector<Category> c;

  c = fetchData("src/data.todo");

  printTasks(c);

  return 0;
}
