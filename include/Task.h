#ifndef TASK_H
#define TASK_H

#include <string>
using namespace std;

class Task {
private:
  bool edited;
  string category;
  string name;

public:
  string getName();
  string getCategory();
  bool getState();

  void setName(string name);
  void setCategory(string category);
  void toggleState();
};

#endif
