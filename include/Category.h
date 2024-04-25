#ifndef CATEGORY_H
#define CATEGORY_H

#include "Task.h"
#include "globals.h"

class Category {
private:
  string name;
  Task tasks[LIMIT];
  int size;

public:

  Category(); 

  // getters
  string getName();
  Task* getTasks();

  // setters
  void setName(string name);
  void setTasks(Task tasks[], int size);
  void push(Task new_task);
  void pop();
};

#endif
