cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-O2") 

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#add_subdirectory(src)

add_executable(runTests test.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

