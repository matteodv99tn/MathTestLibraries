cmake_minimum_required(VERSION 3.10)

project(structure)
set(CMAKE_CXX_STANDARD 17)


add_executable(mainEntry main.cpp)
target_include_directories(mainEntry PRIVATE include)
#target_sources(mainEntry PRIVATE)
target_link_libraries(mainEntry)

#add_subdirectory(tests)

