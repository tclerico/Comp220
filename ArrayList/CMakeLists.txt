cmake_minimum_required(VERSION 3.8)
project(Lab06)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Lab6Tester.cpp ArrayLib.cpp ArrayList.cpp)
add_executable(Lab06 ${SOURCE_FILES})