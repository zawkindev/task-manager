#include "../include/task_manager.h"
#include "../include/transpiler.h"
#include <cstdio>
#include <cstdlib>
#include <string>
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
    case MAIN: {
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
    }

    case ADD: {
      system("clear");
      printNavbar(navbar, navbar.size());
      printTasks(categories);

      std::string task;
      std::string category;

      std::cout << "\ncategory name: ";
      std::cin >> category;

      std::cout << "task name: ";
      std::cin >> task;

      category = trim(category);
      task = trim(task);

      int size = categories.size();

      bool categoryFound = false;
      if (categories.size() > 0) {
        for (Category &c : categories) {
          if (c.getName() == category) {
            c.push(Task(task));
            categoryFound = true;
            break;
          }
        }

        if (!categoryFound) {
          Task tasks[] = {Task(task)};
          categories.push_back(Category(category, tasks, 1));
        }
      } else {
        Task tasks[] = {Task(task)};
        categories.push_back(Category(category, tasks, 1));
      }

      postData(&categories, FILE);

      mode = MAIN;
      navbar.pop_back();

      break;
    }
    case EDIT: {
      system("clear");
      printNavbar(navbar, navbar.size());
      printTasks(categories);

      std::string task;
      std::string category;

      std::cout << "\ncategory name: ";
      std::cin >> category;
      category = trim(category);

      int size = categories.size();

      bool categoryFound = false;
      if (!categories.empty()) {
        for (Category &c : categories) {
          if (c.getName() == category) {
            std::cout << "task index: ";
            std::cin >> task;
            task = trim(task);

            int taskIndex;
            try {
              taskIndex = std::stoi(task);
            } catch (const std::invalid_argument &) {
              std::cerr << "Invalid task index." << std::endl;
              continue;
            } catch (const std::out_of_range &) {
              std::cerr << "Task index out of range." << std::endl;
              continue;
            }

            if (taskIndex < 0 || taskIndex >= c.size + 1) {
              std::cerr << "Task index out of bounds." << std::endl;
              continue;
            }

            std::cin.ignore(); // Ignore any leftover newline character in the
                               // input buffer
            std::string new_name;
            std::cout << "new task name: ";
            std::getline(std::cin, new_name);

            c.getTasks()[taskIndex - 1].setName(new_name);

            categoryFound = true;
            break;
          }
        }

        if (!categoryFound) {
          std::cerr << "Category not found." << std::endl;
        }
      } else {
        std::cerr << "No categories available." << std::endl;
      }

      postData(&categories, FILE);

      mode = MAIN;
      navbar.pop_back();

      break;
    }
    case DELETE: {
      system("clear");
      printNavbar(navbar, navbar.size());
      printTasks(categories);

      std::string task;
      std::string category;

      std::cout << "\ncategory name: ";
      std::cin >> category;
      category = trim(category);

      int size = categories.size();

      bool categoryFound = false;
      if (!categories.empty()) {
        for (Category &c : categories) {
          if (c.getName() == category) {
            std::cout << "task index: ";
            std::cin >> task;
            task = trim(task);

            int taskIndex;
            try {
              taskIndex = std::stoi(task);
            } catch (const std::invalid_argument &) {
              std::cerr << "Invalid task index." << std::endl;
              continue;
            } catch (const std::out_of_range &) {
              std::cerr << "Task index out of range." << std::endl;
              continue;
            }

            if (taskIndex < 1 || taskIndex > c.size) {
              std::cerr << "Task index out of bounds." << std::endl;
              continue;
            }

            // Shift elements to delete the task
            Task *tasks = c.getTasks();
            int numTasks = c.size;
            for (int i = taskIndex - 1; i < numTasks - 1; ++i) {
              tasks[i] = tasks[i + 1];
            }
            c.size -= 1; // Decrease the size of the tasks array

            categoryFound = true;
            break;
          }
        }

        if (!categoryFound) {
          std::cerr << "Category not found." << std::endl;
        }
      } else {
        std::cerr << "No categories available." << std::endl;
      }

      postData(&categories, FILE);

      mode = MAIN;
      navbar.pop_back();

      break;
    }
    }
  }

  return 0;
}
