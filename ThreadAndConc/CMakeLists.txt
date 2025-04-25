cmake_minimum_required(VERSION 4.0)
project(thread)
#[[
    用来指定变量，用宏路径赋值给变量
    aux指定的是 cmake 后接的路径, 且PROJECT_SOURCE_DIR只能在project设置之后才会有路径
    file 指定的是CMakeLists.txt所在的路径
]]
# aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# 设置头文件路径配置
include_directories(${PROJECT_SOURCE_DIR}/include)

#[[ set 可以设置变量 ]]
# set(SRC main.cpp)

# 打印路径
message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")


add_executable(thread ${SRC})