cmake_minimum_required(VERSION 3.5.0)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})
include(FetchContent)
FetchContent_Declare(googletest
 URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
 )

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(COMMON_SRCS
"../src/IPParser.hpp"
"../src/IPStruct.cpp"
)

add_executable(IPParserTests "IPParserTests.cpp" ${COMMON_SRCS})
target_include_directories(IPParserTests PUBLIC "../src")
target_link_libraries(IPParserTests PUBLIC gtest gtest_main)

include(CPack)
set(CPACK_GENERATOR ZIP)



set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")