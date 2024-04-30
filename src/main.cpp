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

  for (int i = 0; i < business.size; i++) {
    std::cout << sub_tasks[i].getName()<<endl;
  }

  return 0;
}
