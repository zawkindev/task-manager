#include "../include/Category.h"
#include "../include/Stack.h"
#include "../include/Task.h"

string Category::getName() { return name; }
Task *Category::getTasks() { return stack.getData(); }

void Category::setName(const string name) { this->name = name; }
