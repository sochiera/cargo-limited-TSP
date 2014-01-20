cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-O2") 

file(GLOB evolutionary_SRC
    "*.hpp"
    "*.cpp"
)

add_executable(Solve ${evolutionary_SRC})
target_link_libraries(Solve)

