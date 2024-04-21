#include "../include/Category.h"

template <class T> Stack<T>::Stack() {
  Task t;
  size = 0;
};
template <class T> T *Stack<T>::getData() { return data; }
template <class T> void Stack<T>::add(T item) { size++; }

string Category::getName() { return name; }
Task *Category::getTasks() { return tasks; }

void Category::setName(const string name) { this->name = name; }
