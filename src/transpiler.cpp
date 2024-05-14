#include "../include/transpiler.h"
#include "../include/task_manager.h"
#include <vector>

#define IN 1
#define OUT 0

void fetchCategoryNames(std::vector<Category> *categories,
                        std::string filename) {
  std::string str;
  std::string name;
  int state;

  readFile(&str, filename);

  state = OUT;
  for (int i = 0; i < str.length(); i++) {
    char c = str[i];

    if (state == OUT && c == '[') {
      state = IN;
      continue;
    }

    if (state == IN) {
      if (c == ']') {
        Task tasks[0];
        categories->push_back(Category(name, tasks, 0));

        state = OUT;
        name = "";
      } else
        name += c;
    }
  }
}
