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

void printNavbar(string bars[], int size) {
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
