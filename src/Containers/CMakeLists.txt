cmake_minimum_required(VERSION 3.5.0)
project(Containers LANGUAGES CXX)

set(HEADERS
    "Array/Array.hpp"
    "Array/ArrayIter.hpp"
    "List/OneForwardNode.hpp"
    "List/OneForwardList.hpp")

add_library(Containers INTERFACE ${HEADERS})
