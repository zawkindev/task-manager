#include "../include/Category.h"
#include "../include/task_manager.h"
// #include <iostream>

int main() {
  Category business;

  Task t1, t2;
  t1.setName("salom");
  t2.setName("xayr");

  Task tasks[] = {t1, t2};

  business.setTasks(tasks, 2);

  formatTasks(business);

  return 0;
}
