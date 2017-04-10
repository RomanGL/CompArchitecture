cmake_minimum_required(VERSION 3.6)
project(BigChars)

set(CMAKE_CXX_STANDARD 11)

include_directories(../MyTerm)

set(SOURCE_FILES BigChars.c BigChars.h)
add_library(BigChars ${SOURCE_FILES})

target_link_libraries(BigChars MyTerm)