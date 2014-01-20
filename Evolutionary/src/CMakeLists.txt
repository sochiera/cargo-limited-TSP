cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-O2") 

file(GLOB evolutionary_SRC
    "defines.hpp"
    "individual.cpp"
    "individual.hpp"
    "population.cpp"
    "population.hpp"
)

add_executable(Solve ${evolutionary_SRC} main.cpp)
target_link_libraries(Solve)

