#include "../include/Category.h"
#include "../include/Task.h"

string Category::getName() { return name; }

Task *Category::getTasks() { return tasks; }

void Category::setName(const string name) { this->name = name; }
