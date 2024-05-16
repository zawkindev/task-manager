#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "Category.h"
#include "Task.h"
#include <cstddef>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <typename T, size_t N> size_t arraySize(T (&arr)[N]) { return N; }

std::string trim(const std::string &str);

void enlargeTextWithSpaces(string *text, int size);

int findMax(Task *tasks, int supposed_size);

void formatTasks(Category *category);

void formatCategories(vector<Category> *categories);

void createFile(string filename);

void readFile(string *str, string filename);

void writeFile(string str, string filename, std::ios::openmode mode);

void printNavbar(vector<string> options, int size);
/*
 * this function takes an array of strings.
 * it should print them in the following order:
 *
 * Main menu > manage tasks
 *
 * if the item of array is equal to "add" or "edit":
 *
 * Main menu > manage tasks > [edit]
 *
 * */

void printTasks(vector<Category> categories);
/*
 * this function takes an array of Tasks.
 * it should print them in the following order:

Business:                                    IT:
  1. Complete market research                  5. Design website
  2. Create marketing campaign                 6. Develop prototype
  3. Analyze financial statements              7. Conduct user testing
  4. Prepare tax documents

 * you can get category and task name by:
 * getCategory()
 * getName()
 * getters of Task class
 *
 * */

void printMenu(vector<string> options, int size);
/*
 * this function takes an array of strings.
 * it should print them in the following order:
  t. manage tasks
  s. settings

  0. exit

 * NOTE:
 *  when the options first element equals to "0" or "m",
 *  there should be an empty line before it
 * */

#endif
