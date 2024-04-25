#ifndef CATEGORY_H
#define CATEGORY_H

#include "Task.h"
#include "globals.h"

class Category {
private:
  string name;
  Task tasks[LIMIT];

public:
  // getters
  string getName();
  Task* getTasks();

  // setters
  void setName(string name);
  void setTasks(Task tasks[]);
  void add(Task newTask);
  void pop();
};

#endif
