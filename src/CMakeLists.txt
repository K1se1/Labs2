cmake_minimum_required(VERSION 3.6.0)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

add_library(IPParser INTERFACE IPParser.hpp)
add_library(IPStruct IPStruct.hpp IPStruct.cpp)
add_executable(lab2 main.cpp)

target_link_libraries(lab2 IPParser IPStruct)
