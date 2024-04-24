#ifndef STACK_H
#define STACK_H

#include "globals.h"

template <class T> class Stack {
private:
  T data[LIMIT];

public:
  int size;

  Stack();

  T *getData() ;
  void add(T item);
  void pop();
};

#endif