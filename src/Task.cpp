#include "../include/Task.h"
#include <string>
using namespace std;

Task::Task() {
  name = "";
  edited = false;
}

string Task::getName() { return name; }
bool Task::getState() { return edited; }

void Task::setName(string name) { this->name = name; }
void Task::toggleState() { this->edited = !this->edited; }
