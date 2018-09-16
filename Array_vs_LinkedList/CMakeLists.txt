cmake_minimum_required(VERSION 3.8)
project(Lab09)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES ArrayList.cpp LinkedNode.cpp ArrayLib.cpp Lab9Tester.cpp IntLinkedList.cpp ListTests.cpp)
add_executable(Lab09 ${SOURCE_FILES})