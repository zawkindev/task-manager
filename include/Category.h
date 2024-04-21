#ifndef CATEGORY_H
#define CATEGORY_H

#include "Task.h"
#include "globals.h"

class Category {
private:
  string name;
  Task tasks[LIMIT];

public:
  string getName();
  Task* getTasks();
};

#endif
