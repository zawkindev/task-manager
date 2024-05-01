#include "../include/Category.h"
#include "../include/task_manager.h"
#include <iostream>

int main() {
  Category business;
  Category IT;

  Task t1, t2, t3, t4;
  t1.setName("sell 13 bitcoins");
  t2.setName("check newspaper everyday");
  t3.setName("fix the bugs in production");
  t4.setName("write a documentation");

  Task tasks1[] = {t1, t2};
  Task tasks2[] = {t3, t4};

  string arr[] = {"salom", "xayr"};

  std::cout << arraySize(arr);

  return 0;
}
