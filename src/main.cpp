#include "../include/task_manager.h"
#include <iostream>

int main() {
  string txt = "salom";
  enlargeTextWithSpaces(&txt, 50);
  std::cout << txt;

  return 0;
}
