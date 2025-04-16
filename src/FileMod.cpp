#include "../include/FileMod.h"

void FileMod::writeToFile(const std::string &file_name, const std::string &content) {
    file = std::fstream(file_name, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "File1 open error" << std::endl;
    }
    file << content;
    file.close();
}

void FileMod::readFromFile(const std::string &file_name) {
    file = std::fstream(file_name, std::ios::in);
    if (!file.is_open()) {
        std::cerr << "File2 open error" << std::endl;
    }
    std::string content;
    while (std::getline(file, content)) {
        std::cout << content << '\n';
    }
    file.close();
}

void FileMod::clearFile(const std::string &file_name) {
    file = std::fstream(file_name, std::ios::out);
    if (!file.is_open()) {
        std::cerr << "File3 open error" << std::endl;
    }
    file.close();
}

bool FileMod::isClear(const std::string &file_name) {
    file = std::fstream(file_name, std::ios::in);
    if (!file.is_open()) {
        std::cerr << "File4 open error" << std::endl;
        return false;
    }
    if (file.peek() == EOF) {
        file.close();
        return false;
    }
    file.close();
    return true;
}

TaskMod FileMod::recordToVec(TaskMod &tasks, const std::string &file_name) {
    file = std::fstream(file_name, std::ios::in);
    if (!file.is_open()) {
        std::cerr << "File open error" << std::endl;
    }

    while (!file.eof()) {
        Task task;
        std::string content;
        std::getline(file, content);
        if (content.empty()) {
            break;
        }
        auto desc_start = content.find_first_of('.');
        auto prior_start = content.find(". priorety - (");

        if (desc_start == std::string::npos || prior_start == std::string::npos) {
            std::cerr << "You can't use program with non tasks file" << std::endl;
            return {};
        }

        std::string disc = content.substr(desc_start, prior_start - desc_start - 1);

        if (prior_start == std::string::npos) {
            std::cerr << "Error: priority format incorrect in line: " << content << std::endl;
            return {};
        }
        std::string prio = content.substr(prior_start + 14);

        prio.erase(std::remove_if(prio.begin(), prio.end(),
            [](char c) { return !isdigit(c); }), prio.end());

        if (!prio.empty()) {
            task.prior = std::stoi(prio);
        } else {
            std::cerr << "Error: invalid priority value in line: " << content << std::endl;
            return {};
        }


        task.id = tasks.setId();
        task.disc = disc;

        tasks.addTask(task);
    }
    file.close();

    return tasks;
}
