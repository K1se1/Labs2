cmake_minimum_required(VERSION 3.5.0)


add_executable(lab3 main.cpp)

target_link_libraries(lab3 Containers)
add_subdirectory(Containers)



set(CPACK_GENERATOR ZIP)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")