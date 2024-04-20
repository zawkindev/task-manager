#include "../include/Task.h"
#include <string>
using namespace std;

string Task::getName() { return name; }
string Task::getCategory() { return category; }
bool Task::getState() { return edited; }

void Task::setName(string name) { name = name; }
void Task::setCategory(string category) { category = category; }
void Task::toggleState() { edited = !edited; }
