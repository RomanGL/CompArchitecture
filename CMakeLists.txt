cmake_minimum_required(VERSION 3.6)
project(ComArcitecture)

set(CMAKE_C_STANDARD 99)

include_directories(SimpleComputer)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../output/lib)

###### Lab1 ######
set(SOURCE_FILES_LAB1 Lab1/main.c)
add_executable(LabApp1 ${SOURCE_FILES_LAB1})
###### Lab1 ######

###### Lab2 ######
set(SOURCE_FILES_LAB2 Lab2/main.c)
add_executable(LabApp2 ${SOURCE_FILES_LAB2})
###### Lab2 ######

add_subdirectory(SimpleComputer)
target_link_libraries(LabApp1 SimpleComputer)