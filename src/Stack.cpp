#include "../include/Stack.h"
#include "../include/Task.h"

template <class T> Stack<T>::Stack() {
  T emptyItem;
  size = 0;
  for (int i = 0; i < LIMIT; i++) {
    data[i] = emptyItem;
  }
};

template <class T> T *Stack<T>::getData() { return data; }

template <class T> void Stack<T>::add(const T item) {
  if (size < LIMIT) {
    this->data[size] = item;
  }
  ++size;
}

template <class T> void Stack<T>::pop() {
  this->data[size] = T();
  --size;
}

template class Stack<Task>;