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
  string ch;
  bool reached_end = false;

  for (int i = 0; i < size; i++) {
    ch = *(text + i);

    if (ch == "__EOA__") {
      reached_end = false;
      continue;
    }

    if (reached_end)
      *text += " ";
  }
};

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
