#include "../include/transpiler.h"
#include "../include/task_manager.h"
#include <ios>
#include <vector>

#define IN 1
#define OUT 0

void getLines(std::vector<string> *lines, std::string *str) {
  std::string line;
  int len = str->length();

  for (int i = 0; i < len; i++) {
    if ((*str)[i] == '\n') {
      if (line.length() > 0) {
        lines->push_back(line);
      }
      line = "";
    } else {
      line += (*str)[i];
    }
  }
}

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

void fetchTasks(Category *category, std::string filename) {
  int state;
  std::string str;
  std::string task_name;
  std::string category_name;
  std::vector<std::string> lines;

  readFile(&str, filename);

  getLines(&lines, &str);

  int size = lines.size();

  for (int i = 0; i < size; i++) {
    std::string l = lines[i];

    for (int j = 0; j < l.length(); j++) {
      char c = l[j];

      if (c == '[') {
        j++;
        category_name = "";

        while ((c = l[j]) != ']') {
          category_name += c;
          j++;
        }

        i++;
      }
    }

    if (category_name == category->getName()) {
      category->push(Task(lines[i]));
    }
  }
}

std::vector<Category> fetchData(std::string filename) {
  std::vector<Category> categories;

  fetchCategoryNames(&categories, filename);

  for (int i = 0; i < categories.size(); i++) {
    fetchTasks(&categories[i], filename);
  }

  return categories;
}

void postData(std::vector<Category> *categories, std::string filename) {
  std::string str;

  for (int i = 0; i < categories->size(); i++) {
    Category c = (*categories)[i];
    Task *tasks = c.getTasks();

    str += "[" + c.getName() + "]\n";

    for (int j = 0; j < c.size; j++) {
      str += (tasks + j)->getName() + "\n";
    }

    str += "\n";
  }

  writeFile(str, filename, std::ios::out);
}
