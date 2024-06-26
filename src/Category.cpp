#include "../include/Category.h"
#include "../include/Task.h"

Category::Category() {
  size = 0;
  // for (int i = 0; i < LIMIT; i++) {
  //   tasks[i] = Task();
  // }
}

Category::Category(string name, Task tasks[], int size) {
  this->setName(name);
  this->setTasks(tasks, size);
};

string Category::getName() { return name; }

Task *Category::getTasks() { return tasks; }

void Category::setName(const string name) { this->name = name; }

void Category::setTasks(Task tasks[], int size) {
  for (int i = 0; i < size; i++) {
    this->tasks[i] = tasks[i];
  }

  this->size = size;
}

void Category::push(Task new_task) {
  tasks[size] = new_task;
  size++;
}

void Category::pop() {
  tasks[size] = Task();
  size--;
}
