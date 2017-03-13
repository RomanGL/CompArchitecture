cmake_minimum_required(VERSION 3.6)
project(MyTerm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES MyTerm.c MyTerm.h)
add_library(MyTerm ${SOURCE_FILES})