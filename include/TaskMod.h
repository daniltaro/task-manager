#ifndef TASKMOD_H
#define TASKMOD_H

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

struct Task {
    int id;
    int prior;
    std::string disc;

    bool operator<(const Task &t) const;

    Task() {
        id = -1;
        prior = -1;
        disc = "";
    };
};

class TaskMod {
public:
    std::vector<Task> tasks;
    std::vector<Task>::iterator begin() { return tasks.begin(); }
    std::vector<Task>::iterator end() { return tasks.end(); }
    std::vector<Task>::const_iterator begin() const { return tasks.begin(); }
    std::vector<Task>::const_iterator end() const { return tasks.end(); }

    void addTask(Task &task);

    void removeTask(const int &id);

    void sortTasks();

    void displayTasks();

    int setId();

    int size();

    Task getById(const int &id);

    TaskMod() {
        std::vector<Task> tasks = std::vector<Task>();
    }
};


#endif //TASKMOD_H
