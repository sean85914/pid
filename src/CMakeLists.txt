cmake_minimum_required(VERSION 2.8.3)
project(pid)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED)

include_directories(include)

add_library(pid SHARED src/pid.cpp)

add_executable(test_pid src/test_pid.cpp)
target_link_libraries(test_pid pid)
