#include "../include/task_manager.h"
#include "../include/globals.h"
#include <iostream>
#include <string>

using namespace std;

int arraySize(string array[]) {
  int i;
  string element;
  for (i = 0; (element = array[i]) != "__EOA__" && i < LIMIT;
       ++i) // EOA means End of Array
    ;

  return i;
};

void enlargeTextWithSpaces(string *text, int size) {
  bool reached_end = false;

  for (int i = 0; i < size; i++) {
    if (i == text->length()) {
      reached_end = true;
      continue;
    }

    if (reached_end)
      *(text) += " ";
  }
};

void formatTasks(Category category) {
  Task *tasks = category.getTasks();
  Task max_task = tasks[findMax(tasks, category.size)];

  for (int i = 0; i < category.size; i++) {
    Task current_task = tasks[i];
    string text = current_task.getName();

    enlargeTextWithSpaces(&text, max_task.getName().length());

    current_task.setName(text);
  };
}

int findMax(Task *tasks, int supposed_size) {
  int max_index = 0;

  for (int i = 0; i < supposed_size; i++) {
    int len = tasks[i].getName().length();

    if (len > max_index)
      max_index = len;
  }

  return max_index;
}

void printNavbar(const string bars[], int size) {
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

void printMenu(const string options[], int size) {
  string element;
  int i;

  for (i = 0; i < size; ++i) {
    element = options[i];
    cout << element << "\n";
    if (options[i + 1] == "m. main menu" || options[i + 1] == "0. exit") {
      cout << "\n";
    }
  }
}
