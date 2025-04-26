cmake_minimum_required(VERSION 4.0)
project(CPP)

file(GLOB SRC ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(CPPLearn ${SRC})