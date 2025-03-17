cmake_minimum_required(VERSION 3.30)
project(TaskModule)

set(CMAKE_CXX_STANDARD 20)

add_executable(TaskModule src/main.cpp src/TaskMod.cpp src/MainTaskMod.cpp src/FileMod.cpp)
