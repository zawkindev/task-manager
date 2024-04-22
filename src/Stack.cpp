#include "../include/Stack.h"

template <class T> Stack<T>::Stack() {
  Task t;
  size = 0;
};
template <class T> T *Stack<T>::getData() { return data; }
template <class T> void Stack<T>::add(T item) {
  if (size < LIMIT) {
    this->data[size] = item;
  }
  ++size;
}

template <class T> void Stack<T>::pop() {
  Task emptyTask;
  this->data[size] = emptyTask;
  --size;
}

