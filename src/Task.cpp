#include "../include/Task.h"
#include <string>
using namespace std;

string Task::getName() { return name; }
string Task::getCategory() { return category; }
bool Task::getState() { return edited; }

void Task::setName(string name) { this->name = name; }
void Task::setCategory(string category) { this->category = category; }
void Task::toggleState() { this->edited = !this->edited; }
