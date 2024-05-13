#include "../include/task_manager.h"
#include <vector>

int main() {
  Task t1[] = {Task("edit the task"), Task("commit latest changes")};
  Task t2[] = {Task("attend to meeting"), Task("buy stocks"),
               Task("bankrot already")};

  std::vector<Category> c = {Category("IT", t1, 2),
                             Category("Business", t2, 3)};


  printTasks(c);

  return 0;
}
