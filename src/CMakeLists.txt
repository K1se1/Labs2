cmake_minimum_required(VERSION 3.5.0)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

add_library(IPParser INTERFACE IPParser.hpp)
add_library(IPStruct IPStruct.hpp IPStruct.cpp)
add_executable(lab2 main.cpp)

target_link_libraries(lab2 IPParser IPStruct)



include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set(CPACK_GENERATOR ZIP)



set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")