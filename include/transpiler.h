#ifndef TRANSPILER_H
#define TRANSPILER_H

#include "Category.h"
#include <iostream>
#include <string>
#include <vector>

void fetchCategoryNames(std::vector<Category> *categories,
                        std::string filename);

void fetchTasks(Category *category, std::string filename);

std::vector<Category> fetchData(std::string filename);

void postData(std::vector<Category> *categories, std::string filename);

#endif
