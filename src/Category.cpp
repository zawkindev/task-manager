#include "../include/Category.h"

string Category::getName() { return name; }
Task *Category::getTasks() { return stack.getData(); }

void Category::setName(const string name) { this->name = name; }
