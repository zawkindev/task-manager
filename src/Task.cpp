#include "../include/Task.h"
using namespace std;

Task::Task() {
  name = "";
  edited = false;
}

Task::Task(string name) : name(name), edited(false) {}

string Task::getName() { return name; }
bool Task::getState() { return edited; }

void Task::setName(const string name) { this->name = name; }
void Task::toggleState() { this->edited = !this->edited; }
