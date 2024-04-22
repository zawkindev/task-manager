#ifndef CATEGORY_H
#define CATEGORY_H

#include "Stack.h"
#include "Task.h"
#include "globals.h"

class Category {
private:
  string name;
  Stack<Task> stack;

public:
  // getters
  string getName();
  Task *getTasks();

  // setters
  void setName(string name);
  void setTasks(Task tasks[]);
  void add(Task newTask);
  void pop();
};

#endif
