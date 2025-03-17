#ifndef FILEMOD_H
#define FILEMOD_H

#include <fstream>
#include <string>
#include "TaskMod.h"
#include <cctype>


class FileMod {
private:
    std::fstream file;

public:
    void writeToFile(const std::string &file_name, const std::string &content);

    void readFromFile(const std::string &file_name);

    void clearFile(const std::string &file_name);

    bool isClear(const std::string &file_name);

    TaskMod recordToVec(TaskMod &tasks, const std::string &file_name);
};


#endif //FILEMOD_H
