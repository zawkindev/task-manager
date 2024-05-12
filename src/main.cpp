#include "../include/task_manager.h"

int main() {
  Task t1, t2;

  t1 = Task("edit");
  t2 = Task("create");

  Category c1;

  c1.push(t1);
  c1.push(t2);

  formatTasks(&c1);

  return 0;
}
