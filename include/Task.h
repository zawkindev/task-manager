#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task {
private:
  bool edited;
  string name;

public:
  Task();
  Task(string name);
  string getName();
  bool getState();

  void setName(string name);
  void toggleState();
};

#endif
