cmake_minimum_required(VERSION 3.5.0)

add_executable(lab3 main.cpp)

target_link_libraries(lab3 Containers)
add_subdirectory(Containers)