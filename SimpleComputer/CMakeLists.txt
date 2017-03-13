cmake_minimum_required(VERSION 3.6)
project(SimpleComputer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES SimpleComputer.c SimpleComputer.h)

add_library(SimpleComputer ${SOURCE_FILES})