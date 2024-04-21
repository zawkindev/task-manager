#ifndef CATEGORY_H
#define CATEGORY_H

#include "Task.h"
#include "globals.h"

template <class T> class Stack {
private:
  T data[LIMIT];

public:
  int size;

  Stack();

  T *getData();
  void add(T item);
  void pop();
};

class Category {
private:
  string name;
  Task tasks[LIMIT];

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
