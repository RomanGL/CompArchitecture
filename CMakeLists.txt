cmake_minimum_required(VERSION 3.6)
project(ComArcitecture)

set(CMAKE_CXX_STANDARD 11)

include_directories(SimpleComputer)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../output/lib)

###### Lab2 ######
set(SOURCE_FILES_LAB2 Lab2/main.c)
add_executable(LabApp2 ${SOURCE_FILES_LAB2})
###### Lab2 ######

add_subdirectory(SimpleComputer)
target_link_libraries(LabApp2 SimpleComputer)