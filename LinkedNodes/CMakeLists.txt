cmake_minimum_required(VERSION 3.8)
project(Lab07)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Lab7Tester.cpp LinkedNode.cpp LinkedQueue.cpp LinkedStack.cpp)
add_executable(Lab07 ${SOURCE_FILES})