cmake_minimum_required(VERSION 3.6)
project(ComArcitecture)

set(CMAKE_CXX_STANDARD 11)

include_directories(SimpleComputer)
include_directories(MyTerm)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../output/lib)

###### Lab2 ######
set(SOURCE_FILES_LAB2 Lab2/main.c)
add_executable(LabApp2 ${SOURCE_FILES_LAB2})
###### Lab2 ######

###### Lab3 ######
set(SOURCE_FILES_LAB3 Lab3/main.c)
add_executable(LabApp3 ${SOURCE_FILES_LAB3})
###### Lab3 ######

add_subdirectory(SimpleComputer)
add_subdirectory(MyTerm)

target_link_libraries(LabApp2 SimpleComputer)
target_link_libraries(LabApp3 MyTerm)