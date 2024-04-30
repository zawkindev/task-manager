#include "../include/Category.h"
#include "../include/task_manager.h"
#include <iostream>

int main() {
  Category business;

  Task t1, t2;
  t1.setName("salomsdjfhalkjsdhflkajshdflkjah");
  t2.setName("xayr");

  Task tasks[] = {t1, t2};

  business.setTasks(tasks, 2);

  formatTasks(&business);

  Task *sub_tasks = business.getTasks();

  for (int j = 0; j < business.size; j++) {
    std::cout << "  " << j + 1 << ". " << sub_tasks[j].getName() << '\n';
  }

  return 0;
}
