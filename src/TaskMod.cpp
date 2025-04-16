#include "../include/TaskMod.h"

bool Task::operator<(const Task &t) const {
    return prior > t.prior;
}

void TaskMod::addTask(Task &task) {
    tasks.push_back(task);
}

void TaskMod::removeTask(const int &id) {
    if (tasks.size() > id) {
        tasks.erase(tasks.begin() + id);
    }
    int i = 1;
    for (auto &task: tasks) {
        task.id = i;
        i++;
    }
}

void TaskMod::sortTasks() {
    std::sort(tasks.begin(), tasks.end());
}

void TaskMod::displayTasks() const {
    for (const Task &task: tasks) {
        std::cout << task.id << ") (priority: " << task.prior << ") " << task.disc << std::endl;
    }
}

int TaskMod::setId() const {
    return tasks.size() + 1;
}

Task TaskMod::getById(const int &id) {
    for (const auto &task: tasks) {
        if (id + 1 == task.id) {
            return task;
        }
    }
}

int TaskMod::size() const {
    return tasks.size();
}
