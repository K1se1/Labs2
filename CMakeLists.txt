cmake_minimum_required(VERSION 3.5.0)
project(lab2 VERSION 0.1.0 LANGUAGES C CXX)


add_library(IPParser INTERFACE IPParser.hpp)
add_library(IPStruct IPStruct.hpp IPStruct.cpp)
add_executable(lab2 main.cpp)

target_link_libraries(lab2 IPParser IPStruct)



include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
