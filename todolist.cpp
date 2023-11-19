#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
public:
    void addTask(const std::string& description) {
        tasks.push_back(Task(description));
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
            return;
        }

        std::cout << "To-Do List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            const Task& task = tasks[i];
            std::cout << i + 1 << ". ";
            if (task.completed) {
                std::cout << "[Completed] ";
            }
            std::cout << task.description << std::endl;
        }
    }

    void markTaskAsCompleted(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            Task& task = tasks[taskIndex - 1];
            task.completed = true;
            std::cout << "Task marked as completed: " << task.description << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            Task removedTask = tasks[taskIndex - 1];
            tasks.erase(tasks.begin() + taskIndex - 1);
            std::cout << "Task removed: " << removedTask.description << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

private:
    std::vector<Task> tasks;
};

int main() {
    ToDoList toDoList;

    while (true) {
        std::cout << "Options:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Quit\n";

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 5) {
            break;
        }

        switch (choice) {
            case 1: {
                std::cin.ignore(); // Consume the newline character from the previous input
                std::cout << "Enter the task description: ";
                std::string description;
                std::getline(std::cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                toDoList.viewTasks();
                size_t taskIndex;
                std::cout << "Enter the index of the task to mark as completed: ";
                std::cin >> taskIndex;
                toDoList.markTaskAsCompleted(taskIndex);
                break;
            }
            case 4: {
                toDoList.viewTasks();
                size_t taskIndex;
                std::cout << "Enter the index of the task to remove: ";
                std::cin >> taskIndex;
                toDoList.removeTask(taskIndex);
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}