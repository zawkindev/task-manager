#include "../include/Category.h"

string Category::getName() { return name; }
Task *Category::getTasks() { return tasks; }

void Category::setName(string name) { this->name = name; }
