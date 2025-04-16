#include "../include/MainTaskMod.h"

void MainTaskMod::run() {
    std::cout << "Write filename: ";
    std::string filename;
    std::cin >> filename;
    std::cin.ignore();
    TaskMod tasks;
    FileMod file;

    if (file.isClear(filename)) {
        bool flag = true;
        while (flag) {
            std::cout << "Do you want to clear file? y/n: ";
            std::string input;
            std::cin >> input;
            std::cin.ignore();
            if (input == "y") {
                file.clearFile(filename);
                flag = false;
            } else if (input == "n") {
                flag = false;
                file.recordToVec(tasks, filename);
            } else {
                std::cout << "Wrong input!" << std::endl;
            }
        }
    }

    while (true) {
        std::cout << "Choose write/read/unsort/sort/delete tasks: ";
        std::string choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == "write") {
            std::string disc;
            std::cout << "Write task:";
            std::getline(std::cin, disc);

            int prior;
            while (true) {
                std::cout << "Write priority (1-10): ";
                std::cin >> prior;

                if (std::cin.fail() || prior < 1 || prior > 10) {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Invalid input! Please enter a number between 1 and 10.\n";
                } else {
                    break;
                }
            }

            Task task;
            task.id = tasks.setId();
            task.prior = prior;
            task.disc = disc;

            tasks.addTask(task);

            file.clearFile(filename);
            for (const Task &task: tasks) {
                file.writeToFile(
                    filename,
                    std::to_string(task.id) + ". " + task.disc +
                    ". priorety - (" + std::to_string(task.prior) + ")\n");
            }
        } else if (choice == "read") {
            if (file.isClear(filename) == true) {
                file.readFromFile(filename);
            } else {
                std::cout << "File is empty\n";
            }
        } else if (choice == "sort" && tasks.size() > 0) {
            tasks.sortTasks();

            file.clearFile(filename);
            for (const Task &task: tasks) {
                file.writeToFile(
                    filename,
                    std::to_string(task.id) + ". " + task.disc +
                    ". priorety - (" + std::to_string(task.prior) + ")\n");
            }
        } else if (choice == "delete" && tasks.size() > 0) {
            std::cout << "Write task number: ";
            int id;
            std::cin >> id;
            std::cin.ignore();
            tasks.removeTask(id - 1);

            file.clearFile(filename);
            for (const Task &task: tasks) {
                file.writeToFile(
                    filename,
                    std::to_string(task.id) + ". " + task.disc +
                    ". priorety - (" + std::to_string(task.prior) + ")\n");
            }
        } else if (choice == "unsort" && tasks.size() > 0) {
            file.clearFile(filename);
            for (int i = 0; i < tasks.size(); ++i) {
                Task task = tasks.getById(i);
                file.writeToFile(
                    filename,
                    std::to_string(task.id) + ". " + task.disc +
                    ". priorety - (" + std::to_string(task.prior) + ")\n");
            }
        }
    }
}
