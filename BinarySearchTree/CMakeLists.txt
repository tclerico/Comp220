cmake_minimum_required(VERSION 3.8)
project(Lab10)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES BST.cpp Lab10Tester.cpp TestLib.cpp)
add_executable(Lab10 ${SOURCE_FILES})