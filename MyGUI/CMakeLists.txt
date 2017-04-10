cmake_minimum_required(VERSION 3.6)
project(MyGUI)

set(CMAKE_CXX_STANDARD 11)

include_directories(../BigChars)
include_directories(../SimpleComputer)
include_directories(../MyTerm)

set(SOURCE_FILES MyGUI.c MyGUI.h)
add_library(MyGUI ${SOURCE_FILES})

target_link_libraries(MyGUI BigChars MyTerm SimpleComputer)