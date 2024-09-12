cmake_minimum_required(VERSION 3.5.0)
project(Containers LANGUAGES CXX)

set(HEADERS
    "Array/Array.hpp")

add_library(Containers INTERFACE ${HEADERS})
