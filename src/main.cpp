#include "../include/task_manager.h"
#include "../include/transpiler.h"
#include <cstdio>
#include <cstdlib>
#include <vector>

#define MAIN 0
#define ADD 1
#define EDIT 2
#define DELETE 3

#define FILE "data/data.todo"

int main() {

  std::vector<std::string> navbar = {"Main menu"};
  std::string input;
  int mode = MAIN;

  while (true) {
    std::vector<Category> categories = fetchData(FILE);

    switch (mode) {
    case MAIN:
      system("clear");

      printNavbar(navbar, navbar.size());
      printTasks(categories);

      std::cout << "\n";
      printMenu(tasks_menu, tasks_menu.size());

      std::cout << "\ninput: ";
      std::cin >> input;

      if (input == "a") {
        mode = ADD;
        navbar.push_back("add");

      } else if (input == "e") {
        mode = EDIT;
        navbar.push_back("edit");

      } else if (input == "d") {
        mode = DELETE;
        navbar.push_back("delete");

      } else if (input == "0") {
        std::exit(0);
      }

      break;

    case ADD:
      std::string task;
      std::string category;

      std::cout << "\ncategory name: ";
      std::cin >> category;

      std::cout << "task name: ";
      std::cin >> task;

      int size = categories.size();

      for (int i = 0; i < size; i++) {
        Category *c = &categories[i];

        if (c->getName() == category) {
          c->push(Task(task));

        } else if (i == categories.size() - 1) {
          Task tasks[] = {Task(task)};
          categories.push_back(Category(category, tasks, 1));
        }
      }

      postData(&categories, FILE);

      mode = MAIN;
      navbar.pop_back();

      break;
    }
  }

  return 0;
}
