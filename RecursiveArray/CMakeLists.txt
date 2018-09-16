cmake_minimum_required(VERSION 3.8)
project(Lab04)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES TestLib.cpp RecursiveArrayLib.cpp Lab4Tester.cpp)
add_executable(Lab04 ${SOURCE_FILES})