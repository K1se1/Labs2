cmake_minimum_required(VERSION 3.6.0)
add_library(IPParser INTERFACE IPParser.hpp)
add_library(IPStruct IPStruct.hpp IPStruct.cpp)
add_executable(lab2 main.cpp)

target_link_libraries(lab2 IPParser IPStruct)
