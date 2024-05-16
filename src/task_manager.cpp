#include "../include/task_manager.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// enlarge text with spaces
string enlargeTextWithSpaces(string text, int size) {
  bool reached_end = false;

  for (int i = 0; i <= size; i++) {
    if (i == text.length()) {
      reached_end = true;
      continue;
    }

    if (reached_end)
      text += " ";
  }

  return text;
};

// find the task with max length name
int findMax(Task *tasks, int supposed_size) {
  int max_index = 0;
  int max_len = 0;

  for (int i = 0; i < supposed_size; i++) {
    int len = tasks[i].getName().length();

    if (len > max_len) {
      max_len = len;
      max_index = i;
    }
  }

  return max_index;
}

void formatTasks(Category *category) {
  Task *tasks = category->getTasks();
  Task max_task = tasks[findMax(tasks, category->size)];

  int max_len = max_task.getName().length();

  if (max_len < category->getName().length()) {
    max_len = category->getName().length();
  }

  for (int i = 0; i < category->size; i++) {
    Task *current_task = &tasks[i];

    string en_text = enlargeTextWithSpaces(current_task->getName(), max_len);

    if (current_task->getName().length() > 0)
      current_task->setName(std::to_string(i + 1) + ". " + en_text);
    else
      current_task->setName("   " + en_text);
  };

  category->setName(enlargeTextWithSpaces(category->getName() + ":",
                                          max_task.getName().length()));
}

void createFile(string filename) { // create a file
  ofstream File(filename);
  File.close();
}

void readFile(string *str, string filename) { // read file
  ifstream File(filename);
  string temp;

  if (File.is_open()) {
    while (getline(File, temp))
      *str += temp + "\n";
  }
}

void writeFile(string str, string filename,
               std::ios::openmode mode) { // write file
  ofstream File(filename, mode);

  if (File.is_open()) {
    File << str;
  }
}

void printNavbar(vector<string> bars, int size) { // print navbar
  string element;
  int i;

  for (i = 0; i < size; ++i) {
    element = bars[i];
    cout << element;

    if (i == size - 1) {
      cout << '\n';
    } else {
      cout << " > ";
    }
  }
}

// prints menu
void printMenu(vector<string> options, int size) {
  string element;
  int i;

  for (i = 0; i < size; ++i) {
    element = options[i];
    cout << element << "\n";
    if (options[i + 1] == "0. back") {
      cout << "\n";
    }
  }
}

// print all todos and categories
void printTasks(vector<Category> categories) {
  vector<string> lines;

  formatCategories(&categories);

  for (int i = 0; i < categories.size(); i++) {
    Category *c = &categories[i];
    Task *c_t = c->getTasks(); // tasks in c

    formatTasks(c);

    if (i % 2 == 1 || (i + 1) % 2 == 0) {
      Category *p = c - 1;       // previous category
      Task *p_t = p->getTasks(); // tasks in p

      lines.push_back("\n" + p->getName() + TAB + TAB + "   " + c->getName() +
                      "\n");

      for (int j = 0; j < c->size; j++) {
        lines.push_back("  " + (p_t + j)->getName() + TAB + TAB +
                        (c_t + j)->getName() + "\n");
      }
    } else if (i == categories.size() - 1) {
      lines.push_back("\n" + c->getName() + "\n");

      for (int j = 0; j < c->size; j++)
        lines.push_back("  " + (c_t + j)->getName() + "\n");
    }
  }

  for (int i = 0; i < lines.size(); i++) {
    std::cout << lines[i];
  }
}

// add empty tasks to the smaller category to be equal to other
void formatCategories(std::vector<Category> *categories) {
  if (categories->size() < 2)
    return;

  Category *c, *p; // current, previous

  for (int i = 1; i < categories->size(); i += 2) {
    c = &categories->at(i);
    p = &categories->at(i - 1);

    int c_size = c->size;
    int p_size = p->size;

    for (int j = 0; j < abs(c_size - p_size); j++) {
      if (c_size > p_size)
        p->push(Task());
      else
        c->push(Task());
    }
  }
}
